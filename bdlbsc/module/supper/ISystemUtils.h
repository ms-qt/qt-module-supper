//
// Created by maohuawei on 2020/3/12.
//

#ifndef MODULES_ISYSTEMUTILS_H
#define MODULES_ISYSTEMUTILS_H

#include <bdlbsc/module/supper/IModule.h>

namespace bdlbsc
{

    class ISystemUtils : public IModule
    {
        Q_OBJECT
    public:
        virtual ~ISystemUtils() = 0;

        virtual QString os() = 0;

        virtual QString local_machinename() = 0;

        virtual QString ip() = 0;

        virtual QString publicip() = 0;

        virtual QString mac() = 0;

        virtual QString cpu_type() = 0;

        virtual QString dcard() = 0;

        virtual QString memory() = 0;

        virtual QString os_version() = 0;

        virtual QString screen() = 0;

        virtual QString disk() = 0;

        virtual bool iplive() = 0;
    };
} // namespace bdlbsc

#endif //MODULES_ISYSTEMUTILS_H
