//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_SYSTEMUTILS_H
#define MODULES_SYSTEMUTILS_H

#include "QDebug"
#include "QSettings"
#include <QDesktopWidget>
#include <QDir>
#include <QFileInfoList>
#include <QHostAddress>
#include <QHostInfo>
#include <QLibrary>
#include <QNetworkAccessManager>
#include <QNetworkInterface>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSysInfo>
#include <QTimer>
#include <bdlbsc/module/supper/ISystemUtils.h>

namespace bdlbsc
{

    class SystemUtils : public ISystemUtils
    {
    public:
        SystemUtils();
        ~SystemUtils();
        QString os() override;

        QString local_machinename() override;

        QString ip() override;

        QString publicip() override;

        QString mac() override;

        QString cpu_type() override;

        QString dcard() override;

        QString memory() override;

        QString os_version() override;

        QString screen() override;

        QString disk() override;

        bool iplive() override;
    };
} // namespace bdlbsc
#endif //MODULES_SYSTEMUTILS_H
