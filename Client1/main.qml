import QtQuick 2.9
import QtQuick.Window 2.2
import org.controller 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        text: "Current state: " + Controller.currentState
        anchors.horizontalCenter: parent.horizontalCenter
    }

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
                    Controller.testFunction("Test function: Client1")
                }
            }
            Text {
                text: "TRUE"
                anchors.centerIn: parent
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
            Text {
                text: "FALSE"
                anchors.centerIn: parent
            }
        }
    }
    Component.onCompleted: {
        console.log("Controller: ", Controller);
    }
}
