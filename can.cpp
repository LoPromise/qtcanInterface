#include "can.h"
#include <QCanBus>

can::can()
{
    can0 = QCanBus::instance()->createDevice(QStringLiteral("socketcan"), QStringLiteral("vcan0"), &errorString);
    if (!can0)
        //qDebug() << errorString;
        ;
    else
        can0->connectDevice();
}
bool can::cansend(qint32 id,const QByteArray &data)
{
    QCanBusFrame frame;
    frame.setPayload(data);
    frame.setFrameId(id);
    can0->writeFrame(frame);
}
