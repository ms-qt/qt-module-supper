//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_MD5UTILS_H
#define MODULES_MD5UTILS_H

#include <bdlbsc/module/supper/IMD5Utils.h>
#include <QCryptographicHash>
namespace bdlbsc
{
    class MD5Utils : public IMD5Utils
    {
    public:
        MD5Utils();
        ~MD5Utils();
        QString md5(QString str) override;
    };
} // namespace bdlbsc
#endif //MODULES_MD5UTILS_H
