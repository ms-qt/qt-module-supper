//
// Created by 毛华伟 on 2020/1/3.
//
#pragma execution_character_set("UTF-8")
#ifndef APP_APPPLUGINMANAGER_H
#define APP_APPPLUGINMANAGER_H

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QObject>
#include <QPluginLoader>
#include <QVariant>
#include <bdlbsc/module/plugin/Plugin.h>
#include <bdlbsc/plugin/supper/IAppPluginInterface.h>
#include <bdlbsc/plugin/supper/PLUGIN_INFO_KEY.h>
#include <bdlbsc/plugin/supper/PluginMetaData.h>

namespace bdlbsc
{

    class AppPluginManager : public QObject
    {
        Q_OBJECT
    public:
        // 获取实例
        static AppPluginManager *get_instance();
        // 加载插件
        void loader(Plugin *plugin);

        const QList<Plugin *> get_plugins() const;

    private:
        // 私有构造函数
        AppPluginManager();
        // 单实例
        static AppPluginManager *_instance;
        // 插件目录
        QDir *_plugins_dir;
        // 插件目录字符串
        QString _plugins_path;
        // 所有的插件集合
        QList<Plugin *> _q_list_plugins;
        // 扫描本地已有插件
        void scan_local_plugin();
        // 检查是否为插件
        bool check_qlibrary(QString path);
        // 检查是否为自己的插件，防止外部注入
        bool me_plugin();

    signals:
        void send_message(bdlbsc::PluginMetaData *data);
    public slots:
        void receive_message(bdlbsc::PluginMetaData *data);

    private:
        QList<Plugin *> _plugins;
        QHash<QString, bdlbsc::IAppPluginInterface *> _plugins_cache;
    };

} // namespace bdlbsc

#endif //APP_APPPLUGINMANAGER_H
