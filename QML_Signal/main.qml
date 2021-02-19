import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        objectName: "myButton1"
        text: "Press me"
        signal buttonClicked(string str)
        x: 10
        y: 20
        onClicked: function() {
        buttonClicked("button clicked");
    }
    }
    Text {
        objectName: "myText1"
        text: "my text"
        x: 10
        y: 50
    }
}
