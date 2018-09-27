#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2>
#include <QQuickStyle>
#include <QCanBus>
#include "backend.h"
#include "can.h"

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
    //Link backend with can

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
