//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef MODULES_MODULES_H
#define MODULES_MODULES_H

#include <QObject>

#include <bdlbsc/module/data/Data.h>
#include <bdlbsc/module/supper/IData.h>
#include <bdlbsc/module/supper/IUtils.h>
#include <bdlbsc/module/utils/Utils.h>

namespace bdlbsc
{

    class Modules : QObject
    {
        Q_OBJECT
    public:
        Modules();
        ~Modules();

        IData *data();
        IUtils *utils();

    private:
        Data *_data;
        Utils *_utils;
    };

} // namespace bdlbsc

#endif //MODULES_MODULES_H
