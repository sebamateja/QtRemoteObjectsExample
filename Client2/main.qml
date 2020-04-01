import QtQuick 2.9
import QtQuick.Window 2.2
import org.controller 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        anchors.fill: parent

        spacing: 10
        Rectangle {
            color: "red"
            width: 100; height: 100

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Controller.pushCurrentState(true)
                    Controller.testFunction("dsds")
                }
            }
        }
        Rectangle {
            color: "red"
            width: 100; height: 100

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Controller.pushCurrentState(false)
                }
            }
        }
    }
    Component.onCompleted: {
        console.log("Controller: ", Controller);
    }
}
