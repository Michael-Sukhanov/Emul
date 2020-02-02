#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);

    connect(socket, &QUdpSocket::readyRead, [=](){
        if( socket->hasPendingDatagrams())
        {
            obj.requestSize = quint16(socket->pendingDatagramSize());
            socket->readDatagram(obj.Prequest,obj.requestSize, &senderAdress, &senderPort);
            obj.Prepare_response();
            for (quint32 i =0 ;i<maxWordsPerPacket;i++) {
             if(obj.Get_info()[i] != 0)
                ui->label_4->setText(ui->label_4->text()+"\n"+ QString::number(i)+ "->" + QString::number(obj.Get_info()[i],16));
            }

            ui->label->setText(QString::number(obj.request[0],16)+"\n"+QString::number(obj.request[1],16));
            ui->label_port->setText(QString::number(senderPort));
            ui->label_Adress->setText(senderAdress.toString());
            if(obj.ready())
            socket->writeDatagram( obj.get_response(), obj.responseSize, QHostAddress::LocalHost, senderPort);
            obj.Clear_response();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    socket->bind(QHostAddress::LocalHost, 50001);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(obj.ready())
    socket->writeDatagram( obj.get_response(), obj.responseSize, QHostAddress::LocalHost, senderPort);
    obj.Clear_response();
}
