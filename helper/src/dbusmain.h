#ifndef DBUSMAIN_H
#define DBUSMAIN_H

#include <QObject>
#include <QtDBus>
#include <QStringList>

class DBusMain : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.coderus.androidshareui")
public:
    explicit DBusMain(QObject *parent = 0);

private:
    void execute(const QStringList &args);

public slots:
    void start();

    Q_NOREPLY Q_SCRIPTABLE void shareFile(const QString &filename, const QString &mimetype);
    Q_NOREPLY Q_SCRIPTABLE void shareText(const QString &data);

};

#endif // DBUSMAIN_H
