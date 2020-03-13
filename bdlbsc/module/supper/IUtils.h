//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef QT_MODULES_IUTILS_H
#define QT_MODULES_IUTILS_H
#include <bdlbsc/module/supper/IMD5Utils.h>
#include <bdlbsc/module/supper/IModule.h>
#include <bdlbsc/module/supper/IStringUtils.h>
#include <bdlbsc/module/supper/ISystemUtils.h>
#include <bdlbsc/module/supper/IThreadUtils.h>
#include <bdlbsc/module/supper/IUUIDUtils.h>

namespace bdlbsc
{
    class IUtils : public IModule
    {
        Q_OBJECT
    public:
        virtual ~IUtils() = 0;
        virtual IMD5Utils *md5_utils() = 0;
        virtual IStringUtils *string_utils() = 0;
        virtual IThreadUtils *thread_utils() = 0;
        virtual IUUIDUtils *uuid_utils() = 0;
        virtual ISystemUtils *system_utils() = 0;
    };
} // namespace bdlbsc

#endif //QT_MODULES_IUTILS_H
