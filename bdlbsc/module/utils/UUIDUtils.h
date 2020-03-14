//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_UUIDUTILS_H
#define MODULES_UUIDUTILS_H

#include <bdlbsc/module/supper/IUUIDUtils.h>
#include <QUuid>
namespace bdlbsc
{

    class UUIDUtils : public IUUIDUtils
    {

    public:
        UUIDUtils();
        ~UUIDUtils();
        QString uuid() override;
    };

} // namespace bdlbsc

#endif //MODULES_UUIDUTILS_H
