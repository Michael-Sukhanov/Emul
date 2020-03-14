#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <IPBusHeaders.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_SendpushButton_clicked();

    void on_clearrequestpushButton_clicked();

    void on_clearresppushButton_clicked();

    void on_ReSendGroupBox_toggled(bool arg1);

    void on_StatusPacket_toggled(bool checked);

    void on_ControlGroupBox_toggled(bool arg1);

    void on_AddTransactionpushButton_clicked();

    void on_pushButtonMoreWords_clicked();

    void on_pushButtonMoreWords_2_clicked();

private:
    void Request_to_little_endian(quint16 requestSize)
    {
        for(quint16 i = 0; i < requestSize; i++)
        request[i] = qToBigEndian(request[i]);
    }

    Ui::MainWindow *ui;
    quint16 counter = 1, transIDcounter = 0;
    quint16 SizeOfDatagramm;
    QUdpSocket* socket;
    quint32 request[368];
    quint16 PacketID = 1;
    char* ch_request = reinterpret_cast<char*>(request);
};
#endif // MAINWINDOW_H
