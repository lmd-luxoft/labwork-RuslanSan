import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    id: _root1
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

/*    function createItem() {
         Qt.createQmlObject("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }", root, "dynamicItem");
     }

     Component.onCompleted: root.createItem();    */

/*    Item {
        id: _BattleField
        width: 200
        height: 200

         Grid {
             id: _grid
            rows: 10
            columns: 10
                   //layoutDirection: _root1.direction
                   spacing: 2
                   move: Transition {
                       NumberAnimation {
                           properties: "x"
                       }
                   }
                   Repeater {
                       model: 100
                       Loader {
                           property int value: index
                           sourceComponent: positionerDelegate
                       }
                   }
               }
        Component {
            id: positionerDelegate
            Rectangle {
                width: 20; height: 20
                color: Qt.rgba(0.8/(parent.value+1),0.8/(parent.value+1),0.8/(parent.value+1),1.0)
                Text {
                    text: parent.parent.value+1
                    color: "white"
                    font.pixelSize: 14
                    anchors.centerIn: parent
                }
            }
        }
    }
    //Item.G
    Button {
        x: 200
        text: "Click me"
        onClicked: function(){
            //40.color = "green";
            //for(var i=1;i<_grid.children.length;i++){
            //      _grid.chidren[i].color="blue"
            //}
            //var i=41;
            // _grid.chidren[i].Rectangle.color="blue";
            //_grid.childAt(5,5).object Rectangle.color="blue";
//positionerDelegate.objectName()
            console.log("obj = ", _grid.childAt(5,5).id);
        }
    }*/

    Rectangle {
        width: 400; height: 400; color: "black"

        Grid {
            id: _grid
            x: 5; y: 5
            rows: 5; columns: 5; spacing: 10

            Repeater { model: 24
                       Rectangle { width: 70; height: 70
                                   color: "lightgreen"

                                   Rectangle {x:10; y:10; width: 50; height: 50
                                               color: "yellow"}
                                   Text { text: index
                                          font.pointSize: 30
                                          anchors.centerIn: parent }

                       }
            }
        }
    }
    Button {
        x: 200
        text: "Click me"
        onClicked: function(){
            _grid.children[15].color="blue";
            _grid.children[15].children[0].color="red";
            //_grid.children[15].children[1].color="red";
        }
    }

}
