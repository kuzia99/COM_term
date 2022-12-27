#ifndef DATAMANAGER_T_H
#define DATAMANAGER_T_H

#include <QByteArray>
#include <cstdint>

class DataManager_t
{
private:
    int packetNum = 0;
    uint8_t ControlSum(QByteArray packet);
public:
    DataManager_t();
    QByteArray AskPacket(int DeviceId, int paramNum);
    double getParamValue(QByteArray);
};

#endif // DATAMANAGER_T_H
