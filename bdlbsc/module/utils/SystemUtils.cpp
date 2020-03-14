//
// Created by 毛华伟 on 2020/3/14.
//

#include "SystemUtils.h"
#include <bdlbsc/module/utils/SystemUtils.h>

namespace bdlbsc
{

    SystemUtils::SystemUtils() {}
    SystemUtils::~SystemUtils() {}

    QString SystemUtils::os()
    {
#if defined(Q_OS_WIN32)
        return "WIN32";
#elif defined(Q_OS_UNIX)
        return "UNIX";
#elif defined(Q_OS_OSX)
        return "MACOS";
#endif
    }

    QString SystemUtils::local_machinename()
    {

        QString machineName = QHostInfo::localHostName();
        return machineName;
    }

    QString SystemUtils::ip()
    {

        QString ip = "";
        QList<QNetworkInterface> interFaceList = QNetworkInterface::allInterfaces();
        for (int i = 0; i < interFaceList.size(); i++) {
            QNetworkInterface interface = interFaceList.at(i);
            if (interface.flags().testFlag(QNetworkInterface::IsRunning)) {
                QList<QNetworkAddressEntry> entryList = interface.addressEntries();
                foreach (QNetworkAddressEntry entry, entryList) {
                    if (QAbstractSocket::IPv4Protocol == entry.ip().protocol() && entry.ip() != QHostAddress::LocalHost
                        && entry.ip().toString().startsWith("192.168.")) {
                        ip = entry.ip().toString();
                        break;
                    }
                }
            }
        }
        return ip;
    }

    QString SystemUtils::publicip()
    {

        QString strIp;
        QString webCode = "";

        if (!webCode.isEmpty()) {
            QString web = webCode.replace(" ", "");
            web = web.replace("\r", "");
            web = web.replace("\n", "");
            QStringList list = web.split("<br/>");
            QString tar = list[3];
            QStringList ip = tar.split("=");
            strIp = ip[1];
        } else
            strIp = "无法获取公网ip";

        return strIp;
    }

    QString SystemUtils::mac()
    {

        QString strMac;

        QList<QNetworkInterface> netList = QNetworkInterface::allInterfaces();
        foreach (QNetworkInterface item, netList) {
            if ((QNetworkInterface::IsUp & item.flags()) && (QNetworkInterface::IsRunning & item.flags())) {
                if (strMac.isEmpty() || strMac < item.hardwareAddress()) {
                    strMac = item.hardwareAddress();
                }
            }
        }
        return strMac;
    }

    QString SystemUtils::cpu_type()
    {

        QSettings *CPU = new QSettings("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", QSettings::NativeFormat);
        QString m_cpuDescribe = CPU->value("ProcessorNameString").toString();
        delete CPU;

        return m_cpuDescribe;
    }

    QString SystemUtils::dcard()
    {
        QString dcard;
        QSettings *DCard = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\services\\nvlddmkm\\Device0", QSettings::NativeFormat);
        QString type = DCard->value("Device Description").toString();
        delete DCard;

        QString dType = type;
        dType.trimmed();
        if (!dType.isEmpty())
            dcard = dType;

        DCard = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\igfx\\Device0", QSettings::NativeFormat);
        type = DCard->value("Device Description").toString();
        delete DCard;

        dType = type;
        dType.trimmed();
        if (!dType.isEmpty())
            dcard = dcard + "\n" + dType;

        DCard = new QSettings("HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\amdkmdap\\Device0", QSettings::NativeFormat);
        type = DCard->value("Device Description").toString();
        delete DCard;

        dType = type;
        dType.trimmed();
        if (!dType.isEmpty())
            dcard = dcard + "\n" + dType;

        dcard.trimmed();
        return dcard;
    }
    QString SystemUtils::memory()
    {
        return QString();
    }

    QString SystemUtils::os_version()
    {
        return QSysInfo::productVersion();
    }

    QString SystemUtils::screen()
    {
        return "";
    }
    QString SystemUtils::disk()
    {
        return "";
    }

    bool SystemUtils::iplive()
    {

        //能接通百度IP说明可以通外网
        QTcpSocket tcpClient;
        tcpClient.abort();
        tcpClient.connectToHost("202.108.22.5", 80);
        //100毫秒没有连接上则判断不在线
        return tcpClient.waitForConnected(100);
    }

} // namespace bdlbsc