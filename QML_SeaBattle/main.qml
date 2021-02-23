import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import RuslanSan.SeaBattle 1.0

Window {
    id: _root1
    width: 1040
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

    BattleFieldView {
        id: _BattleField_Player
    }
    BattleFieldView {
        id: _BattleField_Computer
        playerIsComputer: true
        x: 400
    }

    Button {
        x: 220
        text: "Click me"
        onClicked: function(){
            //_BattleField_Player._grid.children[15].children[0].color="blue";
            //_BattleField_Computer._grid.children[15].children[0].color="chartreuse";

            _BattleField_Computer.children[0].children[15].color="blue";
            _BattleField_Computer.children[0].children[15].children[0].color="red";
            //_grid.children[15].children[1].color="red";

            //bText = webdriver.execute_script("var v = ObjectNameUtils.findChild('button'); return v.text;")
        }
    }
    Label {
        x: 300
        id: _labelCoord
        text: "Coord"
        color: "red"
    }
  /*  Label {
        x: 300
        y: 100
        id: _labelAmountOfCell
        text: _BattleField_Player.amountOfCells
        color: "red"
    }*/

}
