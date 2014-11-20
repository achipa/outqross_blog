import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
//    title: qsTr("Hello World")
    Item {
        anchors.fill: parent
        Button {
            anchors.centerIn: parent
            text: "Hello World"
        }
    }


}
