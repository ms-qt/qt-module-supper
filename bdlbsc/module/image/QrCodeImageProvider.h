//
// Created by 毛华伟 on 2020/1/12.
//

#ifndef DOPER_DAPP_QRCODEIMAGEPROVIDER_H
#define DOPER_DAPP_QRCODEIMAGEPROVIDER_H

#include <bdlbsc/module/qrcode/QRCodeGenerator.h>

#include <QDateTime>
#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>
#include <QQuickImageProvider>
#include <QUuid>

class QrCodeImageProvider : public QQuickImageProvider
{
public:
    QrCodeImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap) {}

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        qDebug() << "id : " << id;

        return refresh(id);
    }

    QPixmap refresh(QString id)
    {
        int levelIndex = 1;
        int versionIndex = 0;
        bool bExtent = true;
        int maskIndex = -1;

        qrEncode.EncodeData(levelIndex, versionIndex, bExtent, maskIndex, id.toUtf8().data());

        int qrImageSize = qrEncode.m_nSymbleSize;
        int encodeImageSize = qrImageSize + (QR_MARGIN * 2);
        QImage encodeImage(encodeImageSize, encodeImageSize, QImage::Format_Mono);
        encodeImage.fill(1);
        for (int i = 0; i < qrImageSize; i++) {
            for (int j = 0; j < qrImageSize; j++) {
                if (qrEncode.m_byModuleData[i][j]) {
                    encodeImage.setPixel(i + QR_MARGIN, j + QR_MARGIN, 0);
                }
            }
        }
        QPixmap mp = QPixmap::fromImage(encodeImage);
        int scale_size = encodeImageSize * 8;
        const QPixmap &scale_image = mp.scaled(scale_size, scale_size);
        return scale_image;
    }

private:
    CQR_Encode qrEncode;
};

#endif //DOPER_DAPP_QRCODEIMAGEPROVIDER_H
