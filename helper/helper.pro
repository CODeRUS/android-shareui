TARGET = androidshareui
target.path = /usr/bin

QT += dbus

SOURCES += \
    src/main.cpp \
    src/adaptor.cpp \
    src/dbusmain.cpp

HEADERS += \
    src/adaptor.h \
    src/dbusmain.h

dbus.files = dbus/org.coderus.androidshareui.service
dbus.path = /usr/share/dbus-1/system-services

systemd.files = systemd/androidshareui.service
systemd.path = /lib/systemd/system

policy.files = policy/org.coderus.androidshareui.conf
policy.path = /etc/dbus-1/system.d

INSTALLS += target dbus systemd policy

HEADERS +=
