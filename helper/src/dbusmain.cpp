#include "dbusmain.h"

#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

DBusMain::DBusMain(QObject *parent) :
    QObject(parent)
{
}

void DBusMain::execute(const QStringList &args)
{
    QString program = "/system/bin/app_process";
    QStringList arguments;
    arguments << "/system/bin";
    arguments << "com.android.commands.am.Am" << "start" << "-a" << "android.intent.action.SEND";
    arguments << "-t";

    arguments << args;

    qDebug() << "Executing" << program << arguments;
    QProcess::startDetached(program, arguments);
}

void DBusMain::start()
{
    if (QDBusConnection::sessionBus().registerService("org.coderus.androidshareui")) {
        QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportScriptableSlots);
    }
    else {
        qApp->quit();
    }
}

void DBusMain::shareFile(const QString &filename, const QString &mimetype)
{
    execute(QStringList() << mimetype << "--eu" << "android.intent.extra.STREAM" << filename);
}

void DBusMain::shareText(const QString &data)
{
    execute(QStringList() << "text/*" << "--es" << "android.intent.extra.TEXT" << data);
}
