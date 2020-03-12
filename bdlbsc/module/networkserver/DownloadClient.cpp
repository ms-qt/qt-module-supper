//#include "DownloadClient.h"
//#include <QFileInfo>
//#include <QNetworkAccessManager>
//
//DownloadClient::DownloadClient()
//{
//    manager = new QNetworkAccessManager();
//}
//
//DownloadClient::~DownloadClient()
//{
//    delete manager;
//}
//
//void DownloadClient::start(QString filepath, QUrl url, int start, int end)
//{
//    qDebug() << "开始下载";
//    QNetworkRequest request(url);
//
//    output.setFileName("a.apk");
//    if (!output.open(QIODevice::Append))
//    {
//        qDebug()<<"文件打开失败";
//
//        return;
//    }
//
//    // 设置开始位置 和 结束位置
//    QString bytes = "bytes=" + QString::number(start) + "-" + QString::number(end);
//
//    qDebug() << " bytes : " << bytes;
//
//    request.setRawHeader(QByteArray("Range"), bytes.toLocal8Bit());
//
//    downedReply = manager->get(request);
//
//    connect(downedReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
//    connect(downedReply, SIGNAL(finished()), this, SLOT(finishDownload()));
//    connect(downedReply, SIGNAL(readyRead()), this, SLOT(downloadReadyRead()));
//    connect(downedReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadError(QNetworkReply::NetworkError)));
//
//    downloadTime.start();
//}
//
////void DownloadClient::start(QUrl url)
////{
////    qDebug() << "开始下载";
////    QString path = url.path();
////    qDebug() << "path : " << path;
////    QFileInfo fileInfo = QFileInfo(path);
////
////    filename = QFileInfo(path).fileName();
////
////    getDownloadType();
////    qDebug() << "downloadflag" << downloadFlag;
////    if (downloadFlag == finishType)
////    {
////        return;
////    }
////
////    output.setFileName(filename + ".downing");
////    if (!output.open(QIODevice::Append))
////    {
////        return;
////    }
////    qDebug() << "output size" << output.size();
////    QNetworkRequest request(url);
////    request.setRawHeader(QByteArray("Range"), QString("bytes=%1-").arg(output.size()).toLocal8Bit());
////    downedReply = manager->get(request);
////
////
////    connect(downedReply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(downloadProgress(qint64, qint64)));
////    connect(downedReply, SIGNAL(finished()), this, SLOT(finishDownload()));
////    connect(downedReply, SIGNAL(readyRead()), this, SLOT(downloadReadyRead()));
////    connect(downedReply, SIGNAL(error(QNetworkReply::NetworkError)), this,SLOT(downloadError(QNetworkReply::NetworkError)));
////
////    downloadTime.start();
////}
//void DownloadClient::pause()
//{
//    if (downedReply != nullptr && downedReply->isRunning()) {
//        downedReply->abort();
//    }
//}
//
//void DownloadClient::finishDownload()
//{
//    qDebug() << "下载完成";
//
//    output.flush();
//    output.rename(filename);
//}
//
//void DownloadClient::downloadError(QNetworkReply::NetworkError err)
//{
//    qDebug() << err;
//}
//
//void DownloadClient::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
//{
//
//    qDebug() << "bytesReceived : " << bytesReceived << " bytesTotal : " << bytesTotal;
//
//    // calculate the download speed （得到下载的时间Ms，需要计算）
//    int speed = bytesReceived * 1000.0 / downloadTime.elapsed();
//    QString unit;
//    if (speed < 1024) {
//        unit = "bytes/s";
//    } else if (speed < 1024 * 1024) {
//        speed /= 1024;
//        unit = "kB/s";
//    } else {
//        speed /= 1024 * 1024;
//        unit = "MB/s";
//    }
//    speedStr = QString::number(int(speed)) + unit;
//    qDebug() << speed << unit;
//    qDebug() << "total size" << bytesTotal;
//}
//
//void DownloadClient::downloadReadyRead()
//{
//    qDebug() << "downloadReadyRead"
//             << "write number ：  " << output.write(downedReply->readAll());
//}
//
//void DownloadClient::getDownloadType()
//{
//    QFileInfo file(filename);
//    if (file.exists()) {
//        downloadFlag = finishType;
//    }
//    QFileInfo file1(filename + ".downing");
//    if (file1.exists()) {
//        downloadFlag = oldType;
//    }
//    downloadFlag = newType;
//}