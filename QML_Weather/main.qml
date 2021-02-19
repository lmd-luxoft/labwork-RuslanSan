import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import com.luxoft.c005 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Weather in thr city")

    Weather{
        id: myWaetherInformer
        city: "Odessa"
        onWeatherChanged: function(p){
            infoPanel.text = p;
        }
    }

    Text {
        id: infoPanel
        x: 10
        y: 10
        width: 100
        height: 200
        color: "green"
        text: qsTr("text")
    }

    Button{
        x: 50
        y: 80
        text: "Press to force update weather"
        onClicked: function(){
            myWaetherInformer.forceUpdate();
        }

   }
    Button{
        x: 50
        y: 120
        text: "Set for Saint Peterburg"
        onClicked: function(){
            myWaetherInformer.city = "Saint Peterburg";
            myWaetherInformer.forceUpdate();
        }
    }
    Button{
        x: 50
        y: 140
        text: "Set for Odessa"
        onClicked: function(){
            myWaetherInformer.city = "Odessa";
            myWaetherInformer.forceUpdate();
        }
    }
}
