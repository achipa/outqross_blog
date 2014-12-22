import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import "Log.js" as Log
import "Data.js" as Data

ApplicationWindow {
    property int margin: 11
    property string statusText

    property list<JSONListModel> todos
    property JSONListModel lists: JSONListModel { }

    property var todoscollection;

    id: appid
    title: qsTr("Meteor-enabled ToDo")
    width: 640
    height: 480
    visible: true

    Qondrite {
        id: asteroid
        meteor_url: "192.168.11.116:3000"
        onOpen: statusText = "Connection to " + url + " established";
        onClose: statusText = "Connection closed";
        onError: statusText = "Error: " + errorString;
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&Main")
            MenuItem {
                text: qsTr("&Reconnect")
                onTriggered: messageDialog.show(qsTr("Reconnect action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    statusBar: StatusBar {
        RowLayout {
            Label { text: statusText }
        }
    }

    BusyIndicator {
        id: busy
        anchors.centerIn: parent
    }

    TabView {
        id: tabview
        anchors.fill: parent
        visible: !busy.visible

        Repeater {
            model: lists.model
            id: tabrepeater

            Tab {
                anchors.margins: margin
                title: model.name + (model.incompleteCount > 0 ? " ("+model.incompleteCount+")" : "")
                ScrollView {
                    ColumnLayout{
                        Repeater {
                            model: todos[index].model
                            CheckBox {
                                Component.onCompleted: console.log("" + index + " " + model._id );
                                property var _id: model._id
                                text: model.text
//                                style.label.pointSize: 22
                                checked: model.checked === "true" ? true : false
                                onCheckedChanged: {
                                    console.log("checkedchanged " + model._id + " " + model.checked);
                                }

                                onClicked: {
                                    busy.visible = true;
                                    statusText = "Sending data...";
//                                    model.checked = checked;
                                    asteroid.update(todoscollection, _id, { listId : model.listId, checked: checked, text: model.text } );
                                    statusText = "Data sent";
                                    busy.visible = false;
                                    destroy();
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Timer {
        id: timer
        interval: 3000
        onTriggered: statusText = "";
        repeat: true
    }

    onStatusTextChanged: timer.restart();
    Component.onCompleted: Data.load();
}
