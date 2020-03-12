
#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include "HttpRequest.h"
#include "HttpResponse.h"
#include <QNetworkRequest>
#include <QNetworkReply>



class HttpClient : public QNetworkAccessManager
{
    Q_OBJECT
public:
    friend class HttpRequest;

    HttpClient();
    ~HttpClient();

    HttpRequest get(const QString &url);
    HttpRequest post(const QString &url);
    HttpRequest put(const QString &url);

    HttpRequest send(const QString &url, Operation op = GetOperation);
};


#endif
