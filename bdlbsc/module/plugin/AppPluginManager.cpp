﻿//
// Created by 毛华伟 on 2020/1/3.
//

#include <bdlbsc/module/plugin/AppPluginManager.h>

namespace bdlbsc
{

    AppPluginManager *AppPluginManager::_instance = nullptr;

    AppPluginManager::AppPluginManager()
    {
        _plugins_path = qApp->applicationDirPath() + "/plugins";

        qDebug() << "plugin dirPath:" << _plugins_path;

        _plugins_dir = new QDir(_plugins_path);

        if (!_plugins_dir->exists()) {
            qDebug() << "plugin dirPath not exists:" << _plugins_path;
            _plugins_dir->mkdir(_plugins_path);
        } else {
            qDebug() << "plugin dirPath is exists:" << _plugins_path;
        }

        scan_local_plugin();
    }

    void AppPluginManager::scan_local_plugin()
    {
        qDebug() << "scan plugin path";

        QDir dir(_plugins_path);
        QStringList nameFilters;
        nameFilters << "*";
        QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);

        for (QString it : files) {
            qDebug() << " file name :" << it;
        }

        qDebug() << " ---------- ";

        for (QString it : files) {
            // 检查是否为插件
            if (check_qlibrary(it)) {
                qDebug() << " find plugin : " << it;
                qDebug() << _plugins_path + it;
                QPluginLoader *loader = new QPluginLoader(_plugins_path + "/" + it);

                // 防止外部插件注入
                bdlbsc::IAppPluginInterface *pluginInterface = qobject_cast<bdlbsc::IAppPluginInterface *>(loader->instance());

                if (pluginInterface) {

                    qDebug() << " find plugin : " << it << "sucess";
                    qDebug() << " ---------- ";

                    QJsonObject json = loader->metaData().value("MetaData").toObject();

                    // 获取插件ID
                    QString id = json.value("id").toString();
                    // 名称
                    QString name = json.value("name").toString();
                    //作者
                    QString author = json.value("author").toString();
                    //时间
                    QString date = json.value("date").toString();
                    // 版本名称
                    QString version_name = json.value("version_name").toString();
                    // 版本号
                    int version_code = json.value("version_code").toInt();
                    // 简介
                    QString desc = json.value("desc").toString();
                    // 本地ICON
                    QString icon_local = json.value("icon_local").toString();
                    // 原创icon
                    QString icon_remotely = json.value("icon_remotely").toString();
                    // 是否强制更新
                    bool force_update = json.value("force_update").toBool();
                    // 是否为独立window
                    bool independent_window = json.value("independent_window").toBool();
                    // main_qml
                    QString main_qml = json.value("main_qml").toString();

                    // 实例化插件
                    Plugin *plugin = new Plugin();
                    plugin->_id = id;
                    plugin->_name = (name);
                    plugin->_author = (author);

                    QDate qDate = QDate::fromString(date, "yyyy/MM/dd");
                    plugin->_date = (qDate.toJulianDay());
                    plugin->_version_name = version_name;
                    plugin->_version_code = version_code;
                    plugin->_desc = (desc);
                    plugin->_icon_local = (icon_local);
                    plugin->_icon_remotely = (icon_remotely);
                    plugin->_force_update = force_update;
                    plugin->_independent_window = independent_window;
                    plugin->_main_qml = main_qml;

                    qDebug() << "  插件名称 : " << name;
                    qDebug() << "  插件作者 : " << author;
                    qDebug() << "  插件版本名称 : " << version_name;
                    qDebug() << "  插件版本号 : " << version_code;
                    qDebug() << "  插件简介 : " << desc;
                    qDebug() << "  插件更新时间 : " << date;
                    qDebug() << "  本地icon : " << icon_local;
                    qDebug() << "  远程icon : " << icon_remotely;
                    qDebug() << "  main_qml : " << main_qml;
                    qDebug() << "  ---------- ";
                    _plugins_cache.insert(name, pluginInterface);
                    _plugins.append(plugin);

                    // 关联信号
                    connect(pluginInterface, SIGNAL(sendMessage(PluginMetaData *)), this, SLOT(receiveMessage(PluginMetaData *)));

                } else {
                    qDebug() << " find plugin : " << it << "fail";
                }
                qDebug() << " ---------- ";
            } else {
                qDebug() << " no lib : " << it << "fail";
            }
        }
    }

    bool AppPluginManager::check_qlibrary(QString path)
    {
        return QLibrary::isLibrary(path);
    }

    bool AppPluginManager::me_plugin()
    {
        return false;
    }

    void AppPluginManager::loader(Plugin *plugin)
    {

        qDebug() << " AppPluginManager::loader ";
        qDebug() << " plugin name : " << plugin->_name;

        bdlbsc::IAppPluginInterface *pluginInterface = _plugins_cache.value(plugin->_name);

        if (pluginInterface) {
            pluginInterface->loader();

            bdlbsc::PluginMetaData *data1 = new bdlbsc::PluginMetaData();
            QString *str = new QString("框架给插件返回TOKEN : 123456");
            data1->set_data(str);

            emit pluginInterface->send_message(data1);

        } else {
            delete pluginInterface;
            pluginInterface = Q_NULLPTR;
        }
    }

    AppPluginManager *AppPluginManager::get_instance()
    {
        if (_instance == nullptr) {
            _instance = new AppPluginManager();
        }
        return _instance;
    }

    const QList<Plugin *> AppPluginManager::get_plugins() const
    {
        return _plugins;
    }

    void AppPluginManager::receive_message(bdlbsc::PluginMetaData *data)
    {
        qDebug() << " AppPluginManager::receiveMessage ";
        // 此处为二级指针，取出一级指针的内容需要添加 *
        qDebug() << " plugin send message to : " << *data->get_data();
    }
} // namespace bdlbsc
