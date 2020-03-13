//
// Created by dev on 2020/3/12.
//

#ifndef MODULES_DATADB_H
#define MODULES_DATADB_H

#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

namespace bdlbsc
{
    class DataDb : public QSqlQueryModel
    {
        Q_OBJECT
        DataDb();
        ~DataDb();

        void set_app_id(QString values);
        void set_app_secret(QString values);
        void set_app_access_token(QString values);
        void set_user_access_token(QString values);
        void set_user_id(QString values);
        void set_base_url(QString values);

        QString get_app_id();
        QString get_app_secret();
        QString get_app_access_token();
        QString get_user_access_token();
        QString get_user_id();
        QString get_base_url();

    private:
        void init();
        QSqlQuery sqlQuery;
        const QString __CREATE_TABLE_DATA__ = "create table _data\n"
                                              "(\n"
                                              "    _id primary key autoincrement,\n"
                                              "    _app_id            varchar(512),\n"
                                              "    _app_secret        varchar(512),\n"
                                              "    _app_access_token  varchar(512),\n"
                                              "    _user_access_token varchar(512),\n"
                                              "    _base_url          varchar(512)\n"
                                              ");";
    };
} // namespace bdlbsc

#endif //MODULES_DATADB_H
