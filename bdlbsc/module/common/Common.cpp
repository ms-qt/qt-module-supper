//
// Created by dev on 2020/3/12.
//

#include <bdlbsc/module/common/Common.h>

namespace bdlbsc
{

    bdlbsc::Common *bdlbsc::Common::instance = nullptr;

    bdlbsc::Common::Common()
    {
        modules = new Modules();
    }

    bdlbsc::Common::~Common() noexcept {}

    bdlbsc::Common *bdlbsc::Common::get_instance()
    {

        if (instance == nullptr) {
            instance = new Common();
        }
        return instance;
    }

    bdlbsc::Modules *bdlbsc::Common::get_modules()
    {
        if (modules == nullptr) {
            modules = new Modules;
        }
        return modules;
    }
} // namespace bdlbsc