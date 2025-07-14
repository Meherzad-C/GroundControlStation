import QtQuick 2.15
import QtLocation 5.15
import QtQuick.Window 2.15
import QtPositioning 5.15


Item {
    id: mainPage
        PositionSource {
            id: positionSource
            updateInterval: 3000
            active: true
            preferredPositioningMethods: PositionSource.AllPositioningMethods
            onPositionChanged: {
                let posData = position.coordinate.toString().split(", ")
                statusBar.latitudeString = posData[0]
                statusBar.longitudeString = posData[1]
                map.center = position.coordinate;
            }
        }

        Map {
            id: map
            anchors.fill: parent

            plugin: Plugin {
                name: "osm"
                PluginParameter {
                    name: "osm.mapping.providersrepository.disabled"
                    value: "true"
                }
            }
            zoomLevel: 15
            Image {
                anchors.fill: parent
                anchors.leftMargin: 40
                source: "qrc:/app/Resources/icons/palcement.png"
                fillMode: Image.PreserveAspectCrop
                visible: Themes.isRadarPlaced
            }

            MapQuickItem {
                coordinate: positionSource.position.coordinate
                anchorPoint.x: userLocationImage.width / 2
                anchorPoint.y: userLocationImage.height / 2
                sourceItem: Image {
                    id: userLocationImage
                    source: "qrc:/app/Resources/icons/back.svg"
                    width: 24
                    height: width
                    anchors.centerIn: parent
                }
            }  
       }
}

