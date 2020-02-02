#include "emulator.h"

Emulator::Emulator()
{

}

void Emulator::Prepare_response()
{
    ready_to_send_response = true;
    PacketHeader request_pack_header = PacketHeader(request[0]);
    if(request_pack_header.ProtocolVersion == 0xf)
        Request_to_little_endian();
    Prepare_Header();
    if(ready_to_send_response)
    {
        if(PacketHeader(request[0]).PacketType == 0x1 && request_pack_header.ProtocolVersion == 0xf)// Тип пакета и старший порядок байт обязательны
        {
            qDebug()<<"Prepare status packet words";
            if(requestSize == 16*Word_size)
            {
                qDebug()<<"Status request packet size is correct";
                for(quint8 i=1; i<requestSize; i++)
                    if(request[i] != 0x0)
                    {
                        ready_to_send_response = false;
                        qDebug()<<"Non Zero word somewhere";
                        break;
                    }
            }
            else
                ready_to_send_response = false;

            if(ready_to_send_response)
                qDebug()<<"Status request is correct";
            else
                qDebug()<<"Incorrect status request";

            response[1] = 0xF8070000;
            response[2] = 0x10000000;
            response[3] = 0xF0020020;
            response[4] = 0x0f0f0f0f;
            response[5] = 0x0f0f0f0f;
            response[6] = 0x0f0f0f0f;
            response[7] = 0x0e070f0f;
            response[8] = 0x200000F0;
            response[9] = 0x200000F0;
            response[10] =0x200000F0;
            response[11] =0x200000F0;
            response[12] =0x200000F0;
            response[13] =0x200000F0;
            response[14] =0x200000F0;
            response[15] =0x200000F0;

            counter += 15;
            responseSize += 15 * Word_size;
            response_to_buffer();
                    }
        if(PacketHeader(request[0]).PacketType == 0x0)
        {
            while(4*counter < requestSize)
                Prepare_Transaction_response();
            response_to_buffer();
        }
        if(PacketHeader(request[0]).PacketType == 0x2 && request_pack_header.ProtocolVersion == 0xf)// Тип пакета и старший порядок байт обязательны
            buffer_to_response();
    }
    if( request_pack_header.ProtocolVersion == 0xf)
        Response_to_Big_endian();
}

void Emulator::Prepare_Header()
{
    qDebug()<<"Готовлю заголовок пакета";
    PacketHeader request_pack_header = PacketHeader(request[0]);
    if(request_pack_header.Rsvd == 0 && request_pack_header.ProtocolVersion == 2 && request_pack_header.PacketType < 3)
    {
        response[0]=quint32(PacketHeader(request_pack_header.PacketType,request_pack_header.PacketID));
        responseSize += Word_size;
        counter=+1;
    }
    else
        ready_to_send_response = false;

}

void Emulator::Prepare_Transaction_response()
{
            TransactionHeader trans_header = TransactionHeader(request[counter]);
            if(trans_header.ProtocolVersion == 2 && trans_header.InfoCode == 0xf)
            {
                switch (trans_header.TypeID) {
                case read:                 Read_transaction(trans_header);
                                           break;
                case nonIncrementingRead:  Non_Incrementing_read_transaction(trans_header);
                                           break;
                case write:                Write_transaction(trans_header);
                                           break;
                case nonIncrementingWrite: Non_Incrementing_write_transaction(trans_header);
                                           break;
                case RMWsum:               RMWsum_transaction(trans_header);
                                           break;
                case RMWbits:              RMWbits_transaction(trans_header);
                                           break;
                case configurationRead:    trans_header.InfoCode = 0x0;
                                           response[counter]=quint32(trans_header);
                                           break;
                case configurationWrite:   trans_header.InfoCode = 0x0;
                                           response[counter]=quint32(trans_header);
                                           break;
                default:                   counter += 1;
                                           responseSize += Word_size;
                                           break;
                }
            }
            else
                response[counter] = quint32(TransactionHeader(trans_header.TypeID,trans_header.Words,trans_header.TransactionID, 0x1));
}

// При наличии нескольких транзакций в пакете, функции работают нормально.
// Определить вывод при переполнении, недозаполнении и т. д.

void Emulator::Write_transaction(TransactionHeader th)
{
    for(quint8 i = 0 ; i < th.Words; i++)
        adress_space[request[counter+1] + i] = request[counter + 2 + i];
    th.InfoCode = 0;
    response[responseSize/4] = quint32(th);
    responseSize += Word_size;
    counter += 2 + th.Words;//Обработать ситуацию, когда число слов для записи
    //не соответствует числу регистров для записи
}

void Emulator::Read_transaction(TransactionHeader th)
{
    th.InfoCode = 0;
    response[responseSize/4] = quint32(th);
    for(quint32 i = 0; i < th.Words; i++ )
    {
        response[responseSize/4+ 1 +i] = adress_space[request[counter +1]+i];
    }
    responseSize += Word_size*(th.Words+1);
    counter += 2;
}

void Emulator::Non_Incrementing_read_transaction(TransactionHeader th)
{
    th.InfoCode = 0;
    response[responseSize/4] = quint32(th);
    if(request[counter+ 1] == FIFO_adress){
        for(quint32 i = 0; i<th.Words; i++)
            response[responseSize/4+ 1 +i] = (FIFO_queue.isEmpty() ? 0x0 : FIFO_queue.dequeue());
        adress_space[FIFO_adress]=(FIFO_queue.isEmpty() ? 0x0 : FIFO_queue.head());
    }
    else
        for(quint32 i = 0; i<th.Words; i++)
            response[responseSize/4+ 1 +i] = adress_space[request[counter +1]];
    responseSize += Word_size*(th.Words + 1);
    counter += 2;
}

void Emulator::Non_Incrementing_write_transaction(TransactionHeader th)
{
    th.InfoCode = 0;
    response[responseSize/4] = quint32(th);
    if(request[counter + 1] == FIFO_adress)
    {
        for(quint32 i = 0; i < th.Words; i++)
            FIFO_queue.enqueue(request[counter + 2 + i]);
        adress_space[FIFO_adress] = FIFO_queue.head();
    }
    else
        for(quint32 i = 0; i<th.Words; i++)
         adress_space[request[counter + 1]]= request[counter + 2 + i];
    responseSize += Word_size;
    counter += 2 + th.Words;
}

void Emulator::RMWbits_transaction(TransactionHeader th)
{
    th.InfoCode = (th.Words == 1 ? 0 : 5);
    response[responseSize/4] = quint32(th);
    response[responseSize/4 + 1] = adress_space[request[counter + 1]];
    adress_space[request[counter + 1]] = (adress_space[request[counter + 1]] & request[counter + 2])|request[counter + 3];
   responseSize += 2*Word_size;
   counter += 3 + th.Words;
}

void Emulator::RMWsum_transaction(TransactionHeader th)
{

    th.InfoCode = (th.Words == 1 ? 0 : 5);
    response[responseSize/4] = quint32(th);
    response[responseSize/4 + 1] = adress_space[request[counter + 1]];
    adress_space[request[counter + 1]]+=request[counter + 2];
    responseSize += 2*Word_size;
    counter +=2+th.Words;


}

void Emulator::response_to_buffer()
{
    if(Hash_counter == 16)
        Hash_counter = 0;
    for(int i = 0; i < Response_Size(); i++)
        *(buffer_responses + Hash_counter*maxWordsPerPacket + i) = response[i];
    Old_response[PacketHeader(response[0]).PacketID] = (buffer_responses + Hash_counter*maxWordsPerPacket);
    Lenghts[PacketHeader(response[0]).PacketID] = Response_Size();
    Hash_counter++;
}

void Emulator::buffer_to_response()
{
    ready_to_send_response = (Lenghts.contains(PacketHeader(request[0]).PacketID)? true : false);
    if(ready_to_send_response)
        for(int i = 0; i < Lenghts[PacketHeader(request[0]).PacketID]; i++)
            response[i] = *(Old_response[PacketHeader(request[0]).PacketID]+i);
    responseSize = Lenghts[PacketHeader(request[0]).PacketID];
}
