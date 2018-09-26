#include "backend.h"
#include <iostream>

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
}

double BackEnd::Temperature()
{
    return dTemperature;
}

void BackEnd::setTemperature(const double &Temperature)
{
    dTemperature = Temperature;
    emit temperatureChanged();
}
