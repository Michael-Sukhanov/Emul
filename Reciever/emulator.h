#ifndef EMULATOR_H
#define EMULATOR_H

#include <QtNetwork/QUdpSocket>
#include <IPbusHeaders.h>
#include <QDebug>
#include <QQueue>
#include <QHash>

const quint16 maxWordsPerPacket = 368;
const quint32 FIFO_adress = 0x00001014;
const quint8 Word_size = sizeof(quint32);

class Emulator
{
public:
    Emulator();
    bool ready(){return ready_to_send_response;}//Если пакет, пришедший с сокета соответствует протоколу, то можно отправлять ответ
    char* get_response(){return Presponse;}
    quint32 response[maxWordsPerPacket];//Ответный пакет
    quint16 Response_Size(){return responseSize;} //Получение размера ответного пакета. Не нужна???
    quint32* Get_info(){return adress_space;}// Получение данных из регистров
    void Prepare_response(); // Формирование ответа на основе запроса
    void Clear_response(){responseSize = 0;} // Функция, подготовки response к следующей отправке
    quint32 request[maxWordsPerPacket]; // Пакет запроса
    char* Prequest = reinterpret_cast<char*>(request);//Для работы с массивом quint32 в дальнейшем
    quint16 requestSize = 0; // Размер запрашивающего пакета, который задается количеством байт, пришедшим с сокета
    char* Presponse = reinterpret_cast<char*>(response); //Указатель на первый элеммент массива ответного пакета переводится в char чтобы отправить по UDP
    quint16 responseSize = 0; // Размер ответного пакета, который задается при его формировании для корректной отправки по UDP протоколу

private:
    quint32 adress_space[65536]; // адрессное пространство, где хранятся все записанные по умолчанию регистры
    bool ready_to_send_response = true; //false если пакет из сокета не соответствует IPbus
    quint16 NextPacketID;
    QQueue<quint32> FIFO_queue; // FIFO ячейка, находящаяся по адресу 0x00001014
    quint16 counter = 0; //Пересчет обработанных слов в request
    quint32* buffer_responses = new quint32[maxWordsPerPacket * 16]; // FTM может хранить 16 пакетов одновременно, поэтому буфер будет таким
    //Для обращеня к буферу использую Хеш-таблицы
    QHash<quint16, quint32*> Old_response; //Хранение адресов заголовков response где ключ - ID заголовка
    QHash<quint16, quint16> Lenghts; //Хранение длин ответных пакетов (для их считывания)
    quint8 Hash_counter = 0;//Счетчик, позволяющий регулировать замену самых старых данных на самые новые


    void buffer_to_response();
    void response_to_buffer();
    void Prepare_Header();
    void Prepare_Transaction_response();
    void Request_to_little_endian()
    {
        for(quint16 i = 0; i < requestSize; i++)
        request[i] = qToBigEndian(request[i]);
    }
    void Response_to_Big_endian()
    {
        for(quint16 i = 0; i < responseSize; i++)
        response[i] = qToBigEndian(response[i]);
    }

//Функции обработчики транзакций
    void Write_transaction(TransactionHeader);
    void Read_transaction(TransactionHeader);
    void Non_Incrementing_read_transaction(TransactionHeader);
    void Non_Incrementing_write_transaction(TransactionHeader);
    void RMWbits_transaction(TransactionHeader);
    void RMWsum_transaction(TransactionHeader);
};

#endif // EMULATOR_H
