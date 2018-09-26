#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2>
#include <QQuickStyle>
#include <QCanBus>
#include "backend.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //Register Backend with qml
    qmlRegisterType<BackEnd>("coolingbackend", 1, 0, "BackEnd");
    //Set Styleseet
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    //Load backend
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //CanSetup
    QString errorString;
    QCanBusDevice *can0 = QCanBus::instance()->createDevice(
        QStringLiteral("socketcan"), QStringLiteral("vcan0"), &errorString);
    if (!can0)
        qDebug() << errorString;
    else
        can0->connectDevice();

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
