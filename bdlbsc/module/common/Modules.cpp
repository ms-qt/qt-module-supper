//
// Created by 毛华伟 on 2020/3/14.
//

#include <bdlbsc/module/common/Modules.h>

namespace bdlbsc
{

    Modules::Modules() {}
    Modules::~Modules() {}

    IData *Modules::data()
    {

        if (_data == nullptr) {

            _data = new Data;
        }

        return _data;
    }

    IUtils *Modules::utils()
    {
        if (_utils == nullptr) {
            _utils = new Utils;
        }
        return _utils;
    }

} // namespace bdlbsc