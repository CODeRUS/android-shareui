#include "adaptor.h"

#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

Adaptor::Adaptor(QObject *parent) :
    QDBusAbstractAdaptor(parent)
{
    qDebug() << "Adaptor created successfully!";
}

Adaptor::~Adaptor()
{
}

void Adaptor::shareFile(const QString &filename, const QString &mimetype)
{
    startIntent(QStringList() << "-t" << mimetype << "--eu" << "android.intent.extra.STREAM" << filename);
}

void Adaptor::shareText(const QString &data)
{
    startIntent(QStringList() << "-t" << "text/*" << "--es" << "android.intent.extra.TEXT" << data);
}

void Adaptor::startIntent(const QStringList &params)
{
    QString ANDROID_ROOT(qgetenv("ANDROID_ROOT"));
    QString program = ANDROID_ROOT + "/bin/app_process";
    QStringList arguments;
    arguments << (ANDROID_ROOT + "/bin");
    arguments << "com.android.commands.am.Am" << "start" << "-a" << "android.intent.action.SEND";
    arguments << params;

    qDebug() << "Executing" << program << arguments;

    QProcess myProcess;
    myProcess.startDetached(program, arguments);
}

