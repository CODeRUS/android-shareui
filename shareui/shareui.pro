TEMPLATE = lib

TARGET = $$qtLibraryTarget(androidshareplugin)
target.path = /usr/lib/nemo-transferengine/plugins

CONFIG += plugin link_pkgconfig
PKGCONFIG += nemotransferengine-qt5

HEADERS += \
    src/transferiface.h \
    src/plugininfo.h \
    src/mediatransfer.h

SOURCES += \
    src/transferiface.cpp \
    src/plugininfo.cpp \
    src/mediatransfer.cpp

qml.files = qml/AndroidShare.qml
qml.path = /usr/share/nemo-transferengine/plugins

INSTALLS += target qml
