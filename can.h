#ifndef CAN_H
#define CAN_H
#include <QCanBus>


class can
{
public:
    can();
    bool cansend(qint32 id,const QByteArray &data);
private:
    QString errorString;
    QCanBusDevice *can0;
};

#endif // CAN_H
