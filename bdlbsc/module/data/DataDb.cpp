//
// Created by dev on 2020/3/12.
//

#include "DataDb.h"

namespace bdlbsc
{

    bdlbsc::DataDb::DataDb()
    {
        // 初始化数据库
        init();
        // 创建表
        if (QSqlDatabase::database().tables().contains(__CREATE_TABLE_DATA__)) {
            qDebug() << __CREATE_TABLE_DATA__ << " 连接成功";
        } else {
            qDebug() << __CREATE_TABLE_DATA__ << " 连接失败 ";
            qDebug() << " 创建消息表 ";
            if (sqlQuery.exec(__CREATE_TABLE_DATA__)) {
                qDebug() << __CREATE_TABLE_DATA__ << "  创建成功";
            } else {
                qDebug() << __CREATE_TABLE_DATA__ << "  创建失败" << sqlQuery.lastError().text();
            }
        }
    }

    bdlbsc::DataDb::~DataDb() noexcept {}

    void bdlbsc::DataDb::init()
    {
        // 初始化数据库
        QSqlDatabase database = QSqlDatabase::database();
        if (!database.isValid()) {
            database = QSqlDatabase::addDatabase("QSQLITE");
            if (!database.isValid())
                qFatal("data  add database: %s", qPrintable(database.lastError().text()));
        }

        const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        if (!writeDir.mkpath("."))
            qFatal("Failed to create writable directory at %s", qPrintable(writeDir.absolutePath()));

        const QString fileName = writeDir.absolutePath() + "/bdlbsc-data-database.sqlite3";

        qDebug() << "data 数据库位置 :  " << fileName;

        database.setDatabaseName(fileName);
        if (!database.open()) {
            qFatal("Cannot open database: %s", qPrintable(database.lastError().text()));
            QFile::remove(fileName);
        }
    }

    void bdlbsc::DataDb::set_app_id(QString values) {}
    void bdlbsc::DataDb::set_app_secret(QString values) {}
    void bdlbsc::DataDb::set_app_access_token(QString values) {}
    void bdlbsc::DataDb::set_user_access_token(QString values) {}
    void bdlbsc::DataDb::set_user_id(QString values) {}
    void bdlbsc::DataDb::set_base_url(QString values) {}

    QString bdlbsc::DataDb::get_app_id()
    {

        return nullptr;
    }
    QString bdlbsc::DataDb::get_app_secret()
    {
        return nullptr;
    }
    QString bdlbsc::DataDb::get_app_access_token()
    {
        return nullptr;
    }
    QString bdlbsc::DataDb::get_user_access_token()
    {
        return nullptr;
    }
    QString bdlbsc::DataDb::get_user_id()
    {
        return nullptr;
    }
    QString bdlbsc::DataDb::get_base_url()
    {
        return nullptr;
    }

} // namespace bdlbsc
