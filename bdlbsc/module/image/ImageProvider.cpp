#include "ImageProvider.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>

ImageProvider::ImageProvider(ImageType type, Flags flags) : QQuickImageProvider(type, flags)
{
    manager = new QNetworkAccessManager;
}

ImageProvider::~ImageProvider()
{
    delete manager;
}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    QUrl url(id);
    QNetworkReply *reply = manager->get(QNetworkRequest(url));
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    if (reply->error() != QNetworkReply::NoError) {
        QImage *img = new QImage();
        img->load("qrc:/images/image_default.png", "PNG");
        // 如果出现错误
        return *img;
    }
    QImage image = QImage::fromData(reply->readAll());
    size->setWidth(image.width());
    size->setHeight(image.height());
    return image;
}
