//
// Created by maohuawei on 2020/2/15.
// 动态加载组件
//
#pragma execution_character_set("utf-8")
#ifndef APP_DYNAMICLOADCOMPONENT_H
#define APP_DYNAMICLOADCOMPONENT_H


#include <QObject>
#include <QString>
#include <QFileSystemWatcher>
#include <QQmlApplicationEngine>

class DynamicLoadComponent : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY statusChanged)

public:
    explicit DynamicLoadComponent(QObject *parent = nullptr);
    virtual ~DynamicLoadComponent();
    Q_INVOKABLE void clear();

    static QQmlApplicationEngine *qmlEngine()
    {
        static QQmlApplicationEngine _engine;
        return &_engine;
    }

    QString url();
    void setUrl(QString url);

signals:
    void statusChanged();

public slots:
    void onFileChanged(QString file);

private:
    QString m_url;
    QFileSystemWatcher m_fileWatch;
    QStringList m_monitorFiles;
    QQmlApplicationEngine *m_engine;
};



#endif //APP_DYNAMICLOADCOMPONENT_H
