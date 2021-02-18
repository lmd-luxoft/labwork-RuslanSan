import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListModel {
        id: friutModel
        ListElement {
            name: "Apple"
            cost: 2.45
        }
        ListElement {
            name: "Orange"
            cost: 2.45
        }
        ListElement {
            name: "Banana"
            cost: 2.45
        }
    }

    Component {
        id: friutDelegate
        Row {
   //         Rectangle {
    //            color: "lightgreen"
                Text
                {
                    text: name
                }
                Text
                {
                    text: " " + cost + "$"
                }
            }
   //     }
    }

    ListView {
        anchors.fill: parent
        model: friutModel
        delegate: friutDelegate

    }
}
