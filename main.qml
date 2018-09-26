import QtQuick 2.11
import QtQuick.Controls 2.4
import coolingbackend 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    color: "#ffffff"
    BackEnd {
            id: backend
    }

    property alias dial: dial
    property alias dial1: dial1
    property alias label2: label2
    property alias label3: label3
    title: qsTr("TemperatureController")
    Row {
        id: row
        width: window.width
        height: window.height

        Column {
            id: column
            width: 200
            height: row.height
            spacing: 10

            Label {
                id: label
                text: qsTr("Temperature")
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Dial {
                id: dial
                live: true
                focusPolicy: Qt.TabFocus
                stepSize: 4
                to: 28
                from: 14
                value: 14
                anchors.horizontalCenter: parent.horizontalCenter
                snapMode: "SnapAlways"
                onValueChanged:  backend.dTemperature = value
            }

            Label {
                id: label2
                text: backend.dTemperature
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Column {
            id: column1
            width: 200
            height: row.height
            spacing: 10

            Label {
                id: label1
                text: qsTr("Fanspeed")
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Dial {
                id: dial1
                enabled: true
                wheelEnabled: false
                stepSize: 1
                to: 8
                from: 0
                value: 0
                snapMode: "SnapAlways"
                anchors.horizontalCenter: parent.horizontalCenter
                onValueChanged: backend.dFanspeed = value
            }

            Label {
                id: label3
                text: backend.dFanspeed
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }


}
