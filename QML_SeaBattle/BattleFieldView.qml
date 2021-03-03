import QtQuick 2.0
import RuslanSan.SeaBattle 1.0



Rectangle {
    width: 400; height: 400; color: "black"
    signal shipsDestroyed()

    Grid {
        id: _grid
        x: 30; y: 60
        rows: _BF.amountOfRows
        columns: _BF.amountOfRows
        spacing: 2

        Repeater { model: (_BF.amountOfRows * _BF.amountOfRows)
            Rectangle { width: 20; height: 20
                color: "lightgreen"

                Rectangle {x:2; y:2; width: 16; height: 16
                    color: "yellow"}
                Text { //text: index
                    font.pointSize: 12
                    anchors.centerIn: parent }

            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (_BF.playerIsComputer) {
                //property int value: 10;
                var x = Math.ceil( (mouse.x-_grid.x) / (_grid.spacing + _grid.children[0].width) ); //function ceil is for rounding of float value (ceil(5.1)=5)
                var y = Math.ceil( (mouse.y-_grid.y) / (_grid.spacing + _grid.children[0].height) );

                //_labelCoord.text = "mouse.x=" + mouse.x + " _grid.spacing="+_grid.spacing+ "_grid.children[0].width="+_grid.children[0].width+" x=" + x + ", y=" +y;
                _labelCoord.text = "x=" + x   + ", y=" +y;
                _BF.fire(x,y);
            }
        }
    }


    BattleField {
        id: _BF
        objectName: "BF"
        onSetCellValue: function(x, y, state)
        {
            var color = "lightblue";
            var colorOuterBox = "lightblue";
            if (state === 1) { color = "white"; colorOuterBox = "#808080FF";};
            if (state === 2) {color = "red"; colorOuterBox = "lightblue";};
            if (state === 3) {color = "black"; colorOuterBox = "red";};

           // if (playerIsComputer) color = "#C8C880FF";
            _grid.children[(y-1)*amountOfRows + (x-1)].color = colorOuterBox;
            _grid.children[(y-1)*amountOfRows + (x-1)].children[0].color=color;
        }
        onAllShipDestroyed: {
            shipsDestroyed();
        }

    }
    property alias playerIsComputer: _BF.playerIsComputer


    Grid {
        id: _AxisX
        x: _grid.x
        y: _grid.y - 23
        rows: 1
        columns: _BF.amountOfRows
        spacing: 2

        Repeater { model: (_BF.amountOfRows)
            Rectangle { width: 20; height: 20
                color: _grid.parent.color

                Text { text: index + 1
                    color: "white"
                    font.pointSize: 12
                    anchors.centerIn: parent }

            }
        }
    }
    Grid {
        id: _AxisY
        x: _grid.x - 23
        y: _grid.y
        rows: _BF.amountOfRows
        columns: 1
        spacing: 2
        //text: "A\nB\nC\nD\nE\nF\nG\nH\nI\nK"

        Repeater { model: (_BF.amountOfRows)
            Rectangle { width: 20; height: 20
                color: _grid.parent.color

                Text { text: String.fromCharCode(65 + index)
                    color: "white"
                    font.pointSize: 12
                    anchors.centerIn: parent
                }

            }
        }
    }

    Text {
        text: _BF.playerIsComputer ? qsTr("Computer") : qsTr("Human")
        color: "yellow"
        x: _grid.x
        font.pointSize: 20
        width: _grid.width
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }

}
