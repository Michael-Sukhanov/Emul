#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    socket = new QUdpSocket(this);
    socket->bind();
    connect(socket, &QUdpSocket::readyRead, [=](){
        if( socket->hasPendingDatagrams())
        {
            quint32 response[368];
            char* Presponse = reinterpret_cast<char*>(response);
            quint16 resp_size = quint16(socket->pendingDatagramSize());
            socket->readDatagram(Presponse, resp_size);
            for (int i=0; i < int(resp_size)/4; i++) {
                            ui->responsetextEdit->append(QString::number(response[i],16));
                        }
        }
    });
    ui->EnterIDlineEdit->setEnabled(false);
    ui->AddTransactionpushButton->setEnabled(false);
    ui->lcdNumbertrans->setEnabled(false);
    ui->label_5->setEnabled(false);
//    qDebug()<<QString::number(quint32(PacketHeader()),16);
    connect(ui->NIWradioButton, &QRadioButton::toggled, this, [=](){ui->BaseAdresslineEdit->setText(QString::number(ui->NIWradioButton->isChecked() ? 0x00001014 : 0x00000000, 16));});
    connect(ui->NIRradioButton, &QRadioButton::toggled, this, [=](){ui->BaseAdresslineEdit->setText(QString::number(ui->NIRradioButton->isChecked() ? 0x00001014 : 0x00000000, 16));});
    connect(ui->OwnIDcheckBox, &QCheckBox::toggled, this, [=](){
        ui->EnterIDlineEdit->setEnabled(ui->OwnIDcheckBox->isChecked() ? true : false);
        ui->label_5->setEnabled(ui->OwnIDcheckBox->isChecked() ? true : false);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_SendpushButton_clicked()
{
    bool ok = true;
    if(ui->ControlGroupBox->isChecked())
    {
        request[0] = quint32(PacketHeader(control, ui->OwnIDcheckBox->isChecked() ? (ui->EnterIDlineEdit->text()).toUInt(&ok,16) : PacketID));
        if(ui->BitOrdercheckBox->isChecked())
            Request_to_little_endian(counter);
        for (quint16 i = 0; i < counter; ++i)
            ui->requesttextEdit->append(QString::number(request[i],16));
        SizeOfDatagramm = counter * sizeof (quint32);
        if(!ui->OwnIDcheckBox->isChecked())
            ++PacketID;
    }
    if(ui->StatusPacket->isChecked())
    {
        request[0] = quint32(PacketHeader());
        for (quint8 i = 1; i < 16; ++i)
            request[i] = 0x0;
        Request_to_little_endian(16);
        SizeOfDatagramm = 16 * sizeof (quint32);
        for (quint8 i = 0; i < 16 ; i++)
            ui->requesttextEdit->append(QString::number(request[i],16));
    }
    if(ui->ReSendGroupBox->isChecked())
    {
        request[0] = quint32(PacketHeader(resend, (ui->lineEditID->text()).toUInt(&ok, 16)));
        Request_to_little_endian(1);
        SizeOfDatagramm = sizeof (quint32);
            ui->requesttextEdit->append(QString::number(request[0],16));
    }
    socket->writeDatagram(ch_request, SizeOfDatagramm, QHostAddress::LocalHost, 50001);
    transIDcounter = 0;
    counter = 1;
    ui->lcdNumbertrans->display(transIDcounter);

}

void MainWindow::on_clearrequestpushButton_clicked()
{
    ui->requesttextEdit->clear();
}



void MainWindow::on_clearresppushButton_clicked()
{
    ui->responsetextEdit->clear();
}

void MainWindow::on_ReSendGroupBox_toggled(bool arg1)
{
    if(arg1)
    {
        ui->lcdNumbertrans->setEnabled(false);
        ui->AddTransactionpushButton->setEnabled(false);
        ui->StatusPacket->setChecked(!arg1);
        ui->ControlGroupBox->setChecked(!arg1);

    }
}

void MainWindow::on_StatusPacket_toggled(bool checked)
{
    if(checked)
    {
    ui->lcdNumbertrans->setEnabled(false);
    ui->AddTransactionpushButton->setEnabled(false);
    ui->ReSendGroupBox->setChecked(!checked);
    ui->ControlGroupBox->setChecked(!checked);
    }
}


void MainWindow::on_ControlGroupBox_toggled(bool arg1)
{

        ui->lcdNumbertrans->setEnabled(arg1);
        ui->AddTransactionpushButton->setEnabled(arg1);

        if(ui->ControlGroupBox->isChecked())
    {
        ui->StatusPacket->setChecked(false);
        ui->ReSendGroupBox->setChecked(false);
    }

}

void MainWindow::on_AddTransactionpushButton_clicked()
{
    bool ok;
    if(ui->ControlGroupBox->isChecked())
    {

        quint32 data = 0x00000001;
        if(ui->WriteradioButton->isChecked())
        {
            request[counter] = quint32(TransactionHeader(write,(ui->WordslineEdit->text()).toInt(&ok, 16),transIDcounter));
            request[counter + 1] = (ui->BaseAdresslineEdit->text()).toInt(&ok, 16);
            for (int var = counter + 2; var < (ui->WordslineEdit->text()).toInt(&ok, 16) + counter + 2; ++var)
            {
                request[var] = data;
                data ++;
            }
            counter += 2 + (ui->WordslineEdit->text()).toInt(&ok, 16);
//            socket->writeDatagram(ch_request, ((ui->WordslineEdit->text()).toInt(&ok, 16) + 3)*sizeof(quint32), QHostAddress::LocalHost, 50001);
//            for (int i = 0;i < (ui->WordslineEdit->text()).toInt(&ok, 16) + 3 ; i++)
//            ui->requestlabel->setText(ui->requestlabel->text() + '\n' + QString::number(request[i],16));

        }
        if(ui->ReadradioButton->isChecked())
        {
            request[counter] = quint32(TransactionHeader(read,(ui->WordslineEdit->text()).toInt(&ok, 16),transIDcounter));
            request[counter + 1] = (ui->BaseAdresslineEdit->text()).toInt(&ok, 16);
            counter += 2;
//            socket->writeDatagram(ch_request, 3 * sizeof(quint32), QHostAddress::LocalHost, 50001);
//            for (int i = 0;i < 3 ; i++)
//            ui->requestlabel->setText(ui->requestlabel->text() + '\n' + QString::number(request[i],16));
        }
        if(ui->NIWradioButton->isChecked())
        {
            request[counter] = quint32(TransactionHeader(nonIncrementingWrite,(ui->WordslineEdit->text().toUInt(&ok, 16)),transIDcounter));
            request[counter + 1] = (ui->BaseAdresslineEdit->text()).toInt(&ok, 16);
            for (int var = counter + 2; var < (ui->WordslineEdit->text()).toInt(&ok, 16) + counter + 2; ++var)
            {
                request[var] = data;
                data ++;
            }
            counter += 2 + (ui->WordslineEdit->text()).toInt(&ok, 16);
//            socket->writeDatagram(ch_request, ((ui->WordslineEdit->text()).toInt(&ok, 16) + 3)*sizeof(quint32), QHostAddress::LocalHost, 50001);
//            for (quint8 i = 0;i < (ui->WordslineEdit->text()).toInt(&ok, 16) + 3 ; i++)
//            ui->requestlabel->setText(ui->requestlabel->text() + '\n' + QString::number(request[i],16));
        }
        if(ui->NIRradioButton->isChecked())
        {
            request[counter] = quint32(TransactionHeader(nonIncrementingRead,(ui->WordslineEdit->text().toUInt(&ok, 16)),transIDcounter));
            request[counter + 1] = (ui->BaseAdresslineEdit->text()).toInt(&ok, 16);
            counter += 2;
//            socket->writeDatagram(ch_request, 3 * sizeof(quint32), QHostAddress::LocalHost, 50001);
//            for (quint8 i = 0;i < 3 ; i++)
//            ui->requestlabel->setText(ui->requestlabel->text() + '\n' + QString::number(request[i],16));
        }
        if(ui->RMWBradioButton->isChecked())
        {
            request[counter] = quint32(TransactionHeader(RMWbits,(ui->WordslineEdit->text().toUInt(&ok, 16)),transIDcounter));
            request[counter + 1] = (ui->BaseAdresslineEdit->text()).toInt(&ok, 16);
            request[counter + 2] = (ui->ANDlineEdit->text()).toInt(&ok, 16);
            request[counter + 3] = (ui->ORlineEdit->text()).toInt(&ok, 16);
            counter += 4;
//            socket->writeDatagram(ch_request, 5 * sizeof(quint32), QHostAddress::LocalHost, 50001);
//            for (quint8 i = 0;i < 5 ; i++)
//            ui->requestlabel->setText(ui->requestlabel->text() + '\n' + QString::number(request[i],16));
        }
        if(ui->RMWSradioButton->isChecked())
        {
            request[counter] = quint32(TransactionHeader(RMWsum,(ui->WordslineEdit->text().toUInt(&ok, 16)),transIDcounter));
            request[counter + 1] = (ui->BaseAdresslineEdit->text()).toInt(&ok, 16);
            request[counter + 2] = (ui->ADDENDlineEdit->text()).toInt(&ok, 16);
            counter += 3;
//            socket->writeDatagram(ch_request, 4 * sizeof(quint32), QHostAddress::LocalHost, 50001);
//            for (quint8 i = 0;i < 4 ; i++)
//            ui->requestlabel->setText(ui->requestlabel->text() + '\n' + QString::number(request[i],16));
        }
        ++transIDcounter;
        ui->lcdNumbertrans->display(transIDcounter);

    }
}

void MainWindow::on_pushButtonMoreWords_clicked()
{
    request[0] = quint32(PacketHeader(control,PacketID));
    request[1] = quint32(TransactionHeader(write, 0xff, 123));
    request[2] = 0x0;
    request[3] = 0xAD;
    request[4] = quint32(TransactionHeader(read,3,124));
    request[5] = 0x0;
    socket->writeDatagram(ch_request, 6 * sizeof (quint32), QHostAddress::LocalHost, 50001);
    for (quint8 i = 0;i < 6 ; i++)
           ui->requesttextEdit->append(QString::number(request[i],16));

}

void MainWindow::on_pushButtonMoreWords_2_clicked()
{
    request[0] = quint32(PacketHeader(control,PacketID));
    request[1] = quint32(TransactionHeader(nonIncrementingWrite, 0xff, 123));
    request[2] = 0x0;
    request[3] = 0xAD;
    request[4] = quint32(TransactionHeader(nonIncrementingRead,3,124));
    request[5] = 0x0;
    socket->writeDatagram(ch_request, 6 * sizeof (quint32), QHostAddress::LocalHost, 50001);
    for (quint8 i = 0;i < 6 ; i++)
           ui->requesttextEdit->append(QString::number(request[i],16));
}
