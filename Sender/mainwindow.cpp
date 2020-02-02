#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <IPBusHeaders.h>

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
                ui->label->setText(ui->label->text()+"\n"+QString::number(response[i],16));
            }
        }
    });
//    qDebug()<<QString::number(quint32(PacketHeader()),16);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    request[0] = quint32(PacketHeader(control,111));
    request[1] = quint32(TransactionHeader(write,2,1));
    request[2] = 0x00000002;
    request[3] = 0xffffffff;
    request[4] = 0x12345678;
    request[5] = quint32(TransactionHeader(write,2,2));
    request[6] = 0x00000004;
    request[7] = 0xfffffff1;
    request[8] = 0x12300678;
    request[9] = quint32(TransactionHeader(read,6,3));
    request[10] = 0x00000001;
    request[11] = quint32(TransactionHeader(nonIncrementingWrite, 2, 4));
    request[12] = 0x00001014;
    request[13] = 0xabcdef98;
    request[14] = 0x11111111;
    request[15] = quint32(TransactionHeader(nonIncrementingRead, 1, 5));
    request[16] = 0x00001014;
    request[17] = quint32(TransactionHeader(RMWbits, 3,6));
    request[18] = 0x00000002;
    request[19] = 0xEEEEEEEE;
    request[20] = 0x00000000;
    request[21] = quint32(TransactionHeader(RMWsum, 3,7));
    request[22] = 0x00000003;
    request[23] = 0x87654321;
    request[24] = quint32(TransactionHeader(read,6,3));
    request[25] = 0x00000001;

    socket->writeDatagram(ch_request, 26*sizeof(quint32), QHostAddress::LocalHost, 50001);

}

void MainWindow::on_pushButton_2_clicked()
{
    request[0] = quint32(PacketHeader(control,0));
    request[1] = quint32(TransactionHeader(write,1,0));
    request[2] = 0x00000002;
    request[3] = 0xffffffff;
    request[4] = quint32(TransactionHeader(RMWsum, 1,1));
    request[5] = 0x00000002;
    request[6] = 0x00000002;
    request[7] = quint32(TransactionHeader(read, 1, 2));
    request[8] = 0x00000002;
    socket->writeDatagram(ch_request, 9*sizeof(quint32), QHostAddress::LocalHost, 50001);
}

void MainWindow::on_pushButton_4_clicked()
{
    request[0] = quint32(PacketHeader(resend,112));
    socket->writeDatagram(ch_request, 1*sizeof(quint32), QHostAddress::LocalHost, 50001);
}



void MainWindow::on_pushButton_3_clicked()
{
    request[0] = qToBigEndian(quint32(PacketHeader(status,112)));
    for(int i=1; i < 16; i++ )
        request[i] = 0x0;
    socket->writeDatagram(ch_request, 16*sizeof(quint32), QHostAddress::LocalHost, 50001);
}

void MainWindow::on_pushButton_5_clicked()
{
    request[0] = quint32(PacketHeader(resend,0));
    socket->writeDatagram(ch_request, 1*sizeof(quint32), QHostAddress::LocalHost, 50001);
}

void MainWindow::on_pushButton_6_clicked()
{
    request[0] = qToBigEndian(quint32(PacketHeader(control,112)));
//    qDebug()<<request[0];
//    qDebug()<<qToLittleEndian(request[0]);
    request[1] = qToBigEndian(quint32(TransactionHeader(write, 1,124)));
    request[2] = qToBigEndian(0x00000003);
    request[3] = qToBigEndian(0x87654321);
    socket->writeDatagram(ch_request, 4*sizeof(quint32), QHostAddress::LocalHost, 50001);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->label->setText("");
}
