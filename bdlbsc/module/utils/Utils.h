//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_UTILS_H
#define MODULES_UTILS_H

#include <bdlbsc/module/supper/IUtils.h>
#include <bdlbsc/module/utils/MD5Utils.h>
#include <bdlbsc/module/utils/StringUtils.h>
#include <bdlbsc/module/utils/SystemUtils.h>
#include <bdlbsc/module/utils/ThreadUtils.h>
#include <bdlbsc/module/utils/UUIDUtils.h>
namespace bdlbsc
{
    class Utils : public IUtils
    {

    public:
        Utils();
        ~Utils();
        IMD5Utils *md5_utils() override;
        IStringUtils *string_utils() override;

        IThreadUtils *thread_utils() override;
        IUUIDUtils *uuid_utils() override;

        ISystemUtils *system_utils() override;

    private:
        MD5Utils *_md5_utils;
        StringUtils *_string_utils;
        SystemUtils *_system_utils;
        ThreadUtils *_thread_utils;
        UUIDUtils *_uuid_utils;
    };

} // namespace bdlbsc

#endif //MODULES_UTILS_H
