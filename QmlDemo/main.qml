import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id : _rect1
        x : 10
        y : 10
        width: 50
        height:50
        color:  "green"
    }
    GreenSquare {
        id : _rect4
        x : 70
        y : 70
    }

    Image {
        id : _image1
        x : 60
        y : 10
        width: 50
        height:50
        source:  "/TAHA.bmp"
    }

    Button {
        x : 10
        y : 80
        id: _button1
        text: "Press me"
        onClicked:
        {
            _rect1.color = "blue"
            title = "new tittle" //parent.title = "new tittle"
        }
    }
}
