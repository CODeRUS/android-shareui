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
    runCommand("am.jar", QStringList() << "com.android.commands.am.Am" << "start" << "-a" << "android.intent.action.SEND" << params);
}

void Adaptor::runCommand(const QString &jar, const QStringList &params)
{
    QString ANDROID_ROOT(qgetenv("ANDROID_ROOT"));
    qputenv("CLASSPATH", QString("%1/framework/%2").arg(ANDROID_ROOT).arg(jar).toUtf8());

    QString program = ANDROID_ROOT + "/bin/app_process";
    QStringList arguments;
    arguments << (ANDROID_ROOT + "/bin") << params;

    qDebug() << "Executing" << program << arguments;

    QProcess myProcess;
    myProcess.startDetached(program, arguments);
}

