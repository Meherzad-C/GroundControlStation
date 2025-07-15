import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Window 2.15

Item {
    Plugin {
        id: osmPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: osmPlugin
        center: QtPositioning.coordinate(19.07283, 72.88261)
        zoomLevel: 10

        property real lastX
        property real lastY

        MapPolyline {
            id: trackLine
            line.width: 3
            line.color: "blue"
            path: []
        }

        MapQuickItem {
            id: currentPositionMarker
            visible: false
            anchorPoint.x: 16
            anchorPoint.y: 16
            sourceItem: Image {
                source: "qrc:/icons/drone.png"
                width: 32
                height: 32
                smooth: true
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.AllButtons

            onPressed: function(mouse) {
                map.lastX = mouse.x
                map.lastY = mouse.y

                if (mouse.button === Qt.RightButton) {
                    let coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                    console.log("Right-click at:", coord.latitude, coord.longitude)
                    map.addWaypoint(coord)
                }
            }

            onPositionChanged: function(mouse) {
                let dx = map.lastX - mouse.x
                let dy = map.lastY - mouse.y
                map.pan(dx, dy)
                map.lastX = mouse.x
                map.lastY = mouse.y
            }

            onWheel: function(wheel) {
                if (wheel.angleDelta.y > 0)
                    map.zoomLevel += 1
                else
                    map.zoomLevel -= 1
            }
        }

        function addWaypoint(coord) {
            console.log("Adding waypoint at:", coord.latitude, coord.longitude)
            let item = Qt.createQmlObject(`
                import QtQuick 2.15
                import QtLocation 5.15
                import QtPositioning 5.15

                MapQuickItem {
                    coordinate: QtPositioning.coordinate(${coord.latitude}, ${coord.longitude})
                    anchorPoint.x: 12
                    anchorPoint.y: 12
                    sourceItem: Image {
                        source: "qrc:/icons/point.png"
                        width: 24
                        height: 24
                    }
                }
            `, map, "Waypoint")

            map.addMapItem(item)
        }

        PositionSource {
            id: positionSource
            active: false
        }

        Item {
            id: signalReceiver
            objectName: "signalReceiver"
            function handlePosition(lat, lon, yaw, idx) {
                let coord = QtPositioning.coordinate(lat, lon)

                trackLine.path.push(coord)
                trackLine.path = trackLine.path  // force update

                currentPositionMarker.coordinate = coord
                currentPositionMarker.visible = true

                // map.center = coord
            }
        }
    }
}
