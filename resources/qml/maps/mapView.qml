import QtQuick 2.15
import QtQuick.Controls 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item {
    width: 800; height: 600

    Plugin {
        id: mapPlugin
        name: "osm"   // or another plugin you prefer
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75)  // example coords
        zoomLevel: 14

        MapQuickItem {
            anchorPoint.x: icon.width / 2
            anchorPoint.y: icon.height
            coordinate: QtPositioning.coordinate(59.91, 10.75)
            sourceItem: Image {
                id: icon
                source: "qrc:/images/drone_icon.png"
                width: 32; height: 32
            }
        }
    }
}
