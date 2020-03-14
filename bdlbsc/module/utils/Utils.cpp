//
// Created by 毛华伟 on 2020/3/14.
//

#include <bdlbsc/module/utils/Utils.h>
#include <bdlbsc/module/utils/MD5Utils.h>

namespace bdlbsc
{
    Utils::Utils() {}
    Utils::~Utils() {}

    IMD5Utils *Utils::md5_utils() {

        if(_md5_utils== nullptr)
        {
            _md5_utils = new MD5Utils;
        }

        return _md5_utils;
    }
    IStringUtils *Utils::string_utils() {


        if(_string_utils==nullptr)
        {
            _string_utils=new StringUtils;
        }

        return _string_utils;

    }


    IThreadUtils * Utils::thread_utils() {

        if(_thread_utils==nullptr)
        {
            _thread_utils=new ThreadUtils;
        }

        return _thread_utils;
    }

    IUUIDUtils *Utils::uuid_utils() {

        if(_uuid_utils==nullptr)
        {
            _uuid_utils=new UUIDUtils;
        }


        return _uuid_utils;

    }
    ISystemUtils *Utils::system_utils() {
        if(_system_utils==nullptr)
        {
            _system_utils=new SystemUtils;
        }
        return _system_utils;
    }

} // namespace bdlbsc