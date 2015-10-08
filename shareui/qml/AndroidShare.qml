import QtQuick 2.1
import Sailfish.Silica 1.0
import Sailfish.TransferEngine 1.0

ShareDialog {
    id: root

    onStatusChanged: {
        if (status == DialogStatus.Opened) {
            accept()
        }
    }

    onAccepted: {
        shareItem.start()
    }

    SailfishShare {
        id: shareItem
        source: root.source
        content: root.content ? root.content : {}
        serviceId: root.methodId

    }

    DialogHeader {
        acceptText: qsTrId("Share to Android")
    }

    BusyIndicator {
        anchors.centerIn: parent
        size: BusyIndicatorSize.Large
        running: true
    }
}

