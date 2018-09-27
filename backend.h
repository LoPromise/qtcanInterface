#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include "can.h"

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double dTemperature READ Temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(double dFanspeed READ Fanspeed WRITE setFanspeed NOTIFY fanspeedChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);

    double Temperature();
    double Fanspeed();
    void setTemperature(const double &Fanspeed);
    void setFanspeed(const double &Temperature);

signals:
    void fanspeedChanged();
    void temperatureChanged();

private:
    double dTemperature,dFanspeed;
    can can0;
};

#endif // BACKEND_H
