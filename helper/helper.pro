TARGET = androidshareui
target.path = /usr/bin

QT += dbus

SOURCES += \
    src/main.cpp \
    src/dbusmain.cpp

HEADERS += \
    src/dbusmain.h

dbus.files = dbus/org.coderus.androidshareui.service
dbus.path = /usr/share/dbus-1/services

INSTALLS += target dbus
