#ifndef ADAPTOR_H
#define ADAPTOR_H

#include <QObject>
#include <QDBusAbstractAdaptor>

class Adaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.coderus.androidshareui")

public:
    explicit Adaptor(QObject *parent = 0);
    virtual ~Adaptor();

public slots:
    void shareFile(const QString &filename, const QString &mimetype);
    void shareText(const QString &data);

private:
    void startIntent(const QStringList &params);
    void runCommand(const QString &jar, const QStringList &params);

};

#endif // ADAPTOR_H
