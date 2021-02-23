import QtQuick 2.0
import RuslanSan.SeaBattle 1.0



Rectangle {
    width: 400; height: 400; color: "black"

    Grid {
        id: _grid
        x: 0; y: 0
        rows: _BF.amountOfRows
        columns: _BF.amountOfRows
        spacing: 2

        Repeater { model: (_BF.amountOfRows * _BF.amountOfRows)
            Rectangle { width: 20; height: 20
                color: "lightgreen"

                Rectangle {x:2; y:2; width: 16; height: 16
                    color: "yellow"}
                Text { text: index
                    font.pointSize: 12
                    anchors.centerIn: parent }

            }
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            //property int value: 10;
            var x = Math.ceil( mouse.x / (_grid.spacing + _grid.children[0].width) ); //function ceil is for rounding of float value (ceil(5.1)=5)
            var y = Math.ceil( mouse.y / (_grid.spacing + _grid.children[0].height) );

            //_labelCoord.text = "mouse.x=" + mouse.x + " _grid.spacing="+_grid.spacing+ "_grid.children[0].width="+_grid.children[0].width+" x=" + x + ", y=" +y;
            _labelCoord.text = "x=" + x   + ", y=" +y;
            _BF.fire(x,y);
        }
    }


    BattleField {
        id: _BF
        onSetCellValue: function(x, y, state)
        {
            var color = "red";
            if (state === 1)
                color = "white";

            if (playerIsComputer) color = "#C8C880FF";
            _grid.children[(y-1)*amountOfRows + (x-1)].color="blue";
            _grid.children[(y-1)*amountOfRows + (x-1)].children[0].color=color;
        }
    }
    //property bool playerIsComputer: "";
    property alias playerIsComputer: _BF.playerIsComputer
    //property alias amountOfCells: _BF.amountOfCells

}
