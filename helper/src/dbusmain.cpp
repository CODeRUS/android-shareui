#include "dbusmain.h"
#include "adaptor.h"

#include <QDebug>
#include <QDBusConnection>
#include <QDBusError>
#include <QCoreApplication>

DBusMain::DBusMain(QObject *parent) :
    QObject(parent)
{
}

void DBusMain::start()
{
    QString service("org.coderus.androidshareui");
    qDebug() << "Starting dbus service" << service << "...";
    bool success = QDBusConnection::systemBus().registerService(service);
    if (!success) {
        qWarning() << "Register service fails!";
        QCoreApplication::exit(0);
        return;
    }

    qDebug() << "Service registered successfully!";

    new Adaptor(this);

    bool object = QDBusConnection::systemBus().registerObject("/", this);
    if (object) {
        qDebug() << "Object registered successfully!";
    }
    else {
        qWarning() << "Register object fails!";
        QCoreApplication::exit(0);
        return;
    }
}
