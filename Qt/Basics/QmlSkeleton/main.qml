import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.0
import io.qt.QmlSkeleton 1.0

Window {
    id: root
    width: 500
    height: 200
    property alias element: element
    visible: true
    title: "QmlSkeleton"

    QmlSkeleton {
        id: qmlskeleton
    }

    GridLayout {
        id: gridLayout
        rows: 3
        anchors.rightMargin: 30
        anchors.margins: 20
        anchors.fill: parent
        columns: 3

        Text {
            id: element
            text: "Your Name:"
            font.pixelSize: 20
            width: 100
        }

        TextField {
            id: nameEntry
            text: ""
            font.pointSize: 20
            focus: true
        }

        Button {
            id: sendBtn
            text: "send"
            font.pixelSize: 20
            onClicked: output.text = qmlskeleton.sayHello(nameEntry.text)
        }

        Text {
            Layout.row: 3
            Layout.columnSpan: 3
            id: output
            text: "hi there"
            font.pixelSize: 20
        }
    }


}
