//
// Created by dev on 2020/3/12.
//

#include "Data.h"

namespace bdlbsc
{
    bdlbsc::Data::Data() {}

    bdlbsc::Data::~Data() {}
    void bdlbsc::Data::set_app_id(QString values)
    {
        redis_client.set("app_id", values.toStdString());
        this->_app_id = values;
    }
    QString bdlbsc::Data::get_app_id()
    {
        QString values;
        redis_client.get("app_id", [&values](cpp_redis::reply &reply) {
            if (reply.is_string())
                values = QString::fromStdString(reply.as_string());
        });
        _app_id = values;
        return _app_id;
    }
    void bdlbsc::Data::set_app_secret(QString values)
    {
        redis_client.set("app_secret", values.toStdString());
        this->_app_secret = values;
    }
    QString bdlbsc::Data::get_app_secret()
    {
        QString values;
        redis_client.get("app_secret", [&values](cpp_redis::reply &reply) {
            if (reply.is_string())
                values = QString::fromStdString(reply.as_string());
        });
        _app_secret = values;
        return _app_secret;
    }
    void bdlbsc::Data::set_app_access_token(QString values)
    {
        redis_client.set("app_access_token", values.toStdString());
        this->_app_access_token = values;
    }
    QString bdlbsc::Data::get_app_access_token()
    {
        QString values;
        redis_client.get("app_access_token", [&values](cpp_redis::reply &reply) {
            if (reply.is_string())
                values = QString::fromStdString(reply.as_string());
        });
        _app_access_token = values;
        return _app_access_token;
    }
    void bdlbsc::Data::set_user_access_token(QString values)
    {
        redis_client.set("user_access_token", values.toStdString());
        this->_user_access_token = values;
    }
    QString bdlbsc::Data::get_user_access_token()
    {
        QString values;
        redis_client.get("user_access_token", [&values](cpp_redis::reply &reply) {
            if (reply.is_string())
                values = QString::fromStdString(reply.as_string());
        });
        _user_access_token = values;
        return _user_access_token;
    }
    void bdlbsc::Data::set_user_id(QString values)
    {
        redis_client.set("user_id", values.toStdString());
        this->_user_id = values;
    }
    QString bdlbsc::Data::get_user_id()
    {
        QString values;
        redis_client.get("user_id", [&values](cpp_redis::reply &reply) {
            if (reply.is_string())
                values = QString::fromStdString(reply.as_string());
        });
        _user_id = values;
        return _user_id;
    }

    QString bdlbsc::Data::get_base_url()
    {
        QString values;
        redis_client.get("base_url", [&values](cpp_redis::reply &reply) {
            if (reply.is_string())
                values = QString::fromStdString(reply.as_string());
        });
        _base_url = values;
        return _base_url;
    }

    void bdlbsc::Data::set_base_url(QString values)
    {
        redis_client.set("base_url", values.toStdString());
        this->_base_url = values;
    }

} // namespace bdlbsc
