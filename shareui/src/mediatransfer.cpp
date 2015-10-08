#include "mediatransfer.h"

MediaTransfer::MediaTransfer(QObject *parent) :
    MediaTransferInterface(parent)
{                          QDBusConnection::systemBus(), this);
}

MediaTransfer::~MediaTransfer()
{

}

bool MediaTransfer::cancelEnabled() const
{
    return false;
}

QString MediaTransfer::displayName() const
{
    return QString("Android");
}

bool MediaTransfer::restartEnabled() const
{
    return false;
}

QUrl MediaTransfer::serviceIcon() const
{
    return QUrl();
}

void MediaTransfer::shareFile(const QString &filename, const QString mimetype)
{
    QProcess::startDetached("/usr/bin/androidshareui", QStringList() << filename << mimetype);
}

void MediaTransfer::shareText(const QString &data)
{
    QProcess::startDetached("/usr/bin/androidshareui", QStringList() << data);
}

void MediaTransfer::cancel()
{
    setStatus(MediaTransferInterface::TransferCanceled);
}

void MediaTransfer::start()
{
    QUrl url = mediaItem()->value(MediaItem::Url).toUrl();
    if (!url.isValid()) {
        QString mimeType = mediaItem()->value(MediaItem::MimeType).toString();
        QString content = mediaItem()->value(MediaItem::ContentData).toString();

        if (mimeType == "text/vcard") {
            QFile tmp(QString("/tmp/%1.vcf").arg(QDateTime::currentMSecsSinceEpoch()));
            if (tmp.open(QFile::WriteOnly)) {
                tmp.write(content.toUtf8());
                tmp.close();

                shareFile("file://" + tmp.fileName(), mimeType);
            }
        }
        else {
            shareText(content);
        }
    }
    else {
        QMimeDatabase db;
        QMimeType mimeType = db.mimeTypeForFile(url.toString());

        shareFile(url.toString(), mimeType.name());
    }
}
