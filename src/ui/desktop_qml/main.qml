import QtQuick 2.0
import QtQuick.Layouts
import QtQuick.Controls
import QuickPlotArea 1.0

Window {
    id: root
    visible: true

    width: 800; height: 640

    Component.onCompleted: {
        x = (Screen.width - width) / 2
        y = (Screen.height - height) / 2
    }

    RowLayout {
        id: loMain
        anchors.fill: parent
        spacing: 10

        PlotArea {
            id: plot
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        ColumnLayout {
            id: loButtons
            spacing: 20

            Layout.fillHeight: true
            Layout.maximumWidth: 150

            Button {
                id: btnTriangle
                text: qsTr("Triangle")
                Layout.fillWidth: true
                onClicked: ctrl.btnTriangleClicked(btnTriangle)
            }
            Label {
                id: lblTriangles
                text: "Count: " + ctrl.statTriangles
                Layout.fillWidth: true
                horizontalAlignment:  Text.AlignHCenter
            }
            Button {
                id: btnCircle
                text: qsTr("Circle")
                Layout.fillWidth: true
                onClicked: ctrl.btnCircleClicked(btnCircle)
            }
            Label {
                id: lblCircles
                text: "Count: " + ctrl.statCircles
                Layout.fillWidth: true
                horizontalAlignment:  Text.AlignHCenter
            }
            Button {
                id: btnSquare
                text: qsTr("Square")
                Layout.fillWidth: true
                onClicked: ctrl.btnSquareClicked(btnSquare)
            }
            Label {
                id: lblSquares
                text: "Count: " + ctrl.statSquares
                Layout.fillWidth: true
                horizontalAlignment:  Text.AlignHCenter
            }
            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
            Button {
                id: btnClear
                text: qsTr("Clear")
                Layout.fillWidth: true
                onClicked: ctrl.btnClearClicked(btnClear)
            }
            Button {
                id: btnPlot
                text: qsTr("Plot")
                Layout.fillWidth: true
                onClicked: ctrl.btnPlotClicked(btnPlot)
            }
        }
    }
}
