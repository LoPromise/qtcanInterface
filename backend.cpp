#include "backend.h"
#include <iostream>
#include "can.h"
#include <string>

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    dTemperature=14;
    dFanspeed=0;
}

double BackEnd::Fanspeed()
{
    return dFanspeed;
}

void BackEnd::setFanspeed(const double &Fanspeed)
{
    dFanspeed = Fanspeed;
    emit fanspeedChanged();
    QByteArray buffer(reinterpret_cast<const char*>(&dFanspeed), sizeof(dFanspeed));
    can0.cansend(0x10,buffer);
}

double BackEnd::Temperature()
{
    return dTemperature;
}

void BackEnd::setTemperature(const double &Temperature)
{
    dTemperature = Temperature;
    emit temperatureChanged();
    QByteArray buffer(reinterpret_cast<const char*>(&dTemperature), sizeof(dTemperature));
    can0.cansend(0x11,buffer);
}
