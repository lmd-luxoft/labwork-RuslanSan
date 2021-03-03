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


    BattleFieldView {
        id: _BattleField_Player
        objectName: "BattleField_Player"
        onShipsDestroyed: {
            _labelAllShipsDestroyed.text = "Game over. Computer has won! "
        }
    }
    BattleFieldView {
        id: _BattleField_Computer
        objectName: "BattleField_Computer"
        playerIsComputer: true
        x: 400
        onShipsDestroyed: {
            _labelAllShipsDestroyed.text = "Game over. Player has won!"
        }
    }

    Label {
        x: 300
        y: 60
        id: _labelCoord
        text: "Coord"
        color: "red"
    }

    Label {
        id: _labelAllShipsDestroyed
        x: 270
        y: 100
        text: ""
        color: "red"
    }

}
