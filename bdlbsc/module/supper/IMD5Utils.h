//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef MODULES_IMD5_H
#define MODULES_IMD5_H
#include <bdlbsc/module/supper/IModule.h>
#include <QObject>

namespace bdlbsc
{

    class IMD5Utils : public IModule
    {
        Q_OBJECT
    public:
        virtual ~IMD5Utils() = 0;
    };

} // namespace bdlbsc

#endif //MODULES_IMD5_H
