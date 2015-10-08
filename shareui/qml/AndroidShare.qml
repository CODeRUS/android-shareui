import QtQuick 2.1
import Sailfish.Silica 1.0
import Sailfish.TransferEngine 1.0

ShareDialog {
    id: root

    // Hacka hacking hacky-hacky hacked hacku hacka hack.
    Connections {
        target: __silica_applicationwindow_instance
        onApplicationActiveChanged: {
            if (!__silica_applicationwindow_instance.applicationActive) {
                shareItem.start()
                accept()
            }
        }
    }

    Component.onCompleted: {
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

