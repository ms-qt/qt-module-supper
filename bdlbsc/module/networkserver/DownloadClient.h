//#pragma once
//
//#include <QFile>
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
//#include <QObject>
//
//class DownloadClient : public QObject
//{
//    Q_OBJECT
//public:
//    enum downloadType
//    {
//        newType = 0,
//        oldType,
//        finishType,
//    };
//
//    DownloadClient();
//
//    ~DownloadClient();
//
//    void start(QString file_path, QUrl url, int start, int end);
//
//    void pause();
//
//    void getDownloadType();
//
//public slots:
//
//    void finishDownload();
//
//    void downloadError(QNetworkReply::NetworkError);
//
//    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
//
//    void downloadReadyRead();
//
//private:
//    QNetworkAccessManager *manager;
//    QFile output;
//    QNetworkReply *downedReply;
//    QString filename;
//    QTime downloadTime;
//    int downloadFlag;
//    QString speedStr;
//};
