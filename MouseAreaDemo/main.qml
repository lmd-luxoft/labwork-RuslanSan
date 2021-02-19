import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        width: 100
        height: 100
        Text {
            id: text1
            text: qsTr("Press me")
            anchors.centerIn: parent
        }
        color: "yellow"

        MouseArea {
            anchors.fill: parent
            property string oldColor: "";
            onClicked: {
                if ( oldColor != "") {
                    parent.color = oldColor;
                    oldColor="";
                }
                else {
                    oldColor=parent.color;
                    parent.color="red";
                }

            }

        }
    }
}
