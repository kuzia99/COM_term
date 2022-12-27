#include "datamanager_t.h"
#include "mainwindow.h"

DataManager_t::DataManager_t()
{

}

uint8_t DataManager_t::ControlSum(QByteArray packet)
{
    uint32_t result = 0;
    for (int i = 1; i < packet.length(); i++)
        result += packet.at(i);
    return result & 0xFF;
}

QByteArray DataManager_t::AskPacket(int DeviceId, int paramNum)
{
    QByteArray packet;
    packet.push_back(0x10);
    packet.push_back(0x40 + (packetNum++ & 0xF));
    packet.push_back((char)0x01);
    packet.push_back(DeviceId);
    packet.push_back(paramNum & 0xFF);
    packet.push_back((paramNum & 0xFF00) >> 8 );
    packet.push_back((char)0);
    packet.push_back(ControlSum(packet));
    packet.push_back(0x16);
    return packet;
}

double DataManager_t::getParamValue(QByteArray response)
{
    uint8_t* ptr = (uint8_t*)response.data() + 3;
    float val = *reinterpret_cast<float*>(ptr);
    return val;
}
