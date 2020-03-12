//
// Created by maohuawei on 2020/2/10.
//
#pragma execution_character_set("utf-8")

#ifndef DOPER_DAPP_IMAGEASYNCIMAGEPROVIDER_H
#define DOPER_DAPP_IMAGEASYNCIMAGEPROVIDER_H

#include <QDebug>
#include <QEventLoop>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QThreadPool>
#include <qqmlengine.h>
#include <qquickimageprovider.h>

// 图片加载异步

class AsyncImageResponseRunnable
    : public QObject
    , public QRunnable
{
    Q_OBJECT
signals:

    void done(QImage image);

public:
    AsyncImageResponseRunnable(const QString &id, const QSize &requestedSize) : m_id(id), m_requestedSize(requestedSize)
    {
        manager = new QNetworkAccessManager();
    }

    void run() override
    {
        qDebug() << "id : " << m_id;
        QUrl url(m_id);
        QNetworkReply *reply = manager->get(QNetworkRequest(url));
        QEventLoop eventLoop;
        QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
        eventLoop.exec();

        if (reply->error() != QNetworkReply::NoError) {
            QImage *img = new QImage();
            img->load(":/images/image_default.png", "PNG");
            emit done(*img);
            return;
        }

        QImage image = QImage::fromData(reply->readAll());
        m_requestedSize.setWidth(image.width());
        m_requestedSize.setHeight(image.height());
        emit done(image);
    }

private:
    QString m_id;
    QSize m_requestedSize;
    QNetworkAccessManager *manager;
};

class AsyncImageResponse : public QQuickImageResponse
{
public:
    AsyncImageResponse(const QString &id, const QSize &requestedSize, QThreadPool *pool)
    {
        auto runnable = new AsyncImageResponseRunnable(id, requestedSize);
        connect(runnable, &AsyncImageResponseRunnable::done, this, &AsyncImageResponse::handleDone);
        pool->start(runnable);
    }

    void handleDone(QImage image)
    {
        m_image = image;
        emit finished();
    }

    QQuickTextureFactory *textureFactory() const override
    {
        return QQuickTextureFactory::textureFactoryForImage(m_image);
    }

    QImage m_image;
};

class AsyncImageProvider : public QQuickAsyncImageProvider
{
public:
    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override
    {
        AsyncImageResponse *response = new AsyncImageResponse(id, requestedSize, &pool);
        return response;
    }

private:
    QThreadPool pool;
};

#endif //DOPER_DAPP_IMAGEASYNCIMAGEPROVIDER_H
