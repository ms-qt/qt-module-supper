//
// Created by 毛华伟 on 2020/3/14.
//

#include <bdlbsc/module/utils/MD5Utils.h>

namespace bdlbsc
{
    MD5Utils::MD5Utils() {}
    MD5Utils::~MD5Utils() {}
    QString MD5Utils::md5(QString str)
    {
        QString md5;
        QByteArray ba, bb;
        QCryptographicHash md(QCryptographicHash::Md5);
        ba.append(str);
        md.addData(ba);
        bb = md.result();
        md5.append(bb.toHex());
        return md5;
    }
} // namespace bdlbsc
