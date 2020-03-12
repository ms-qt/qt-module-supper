//
// Created by maohuawei on 2020/3/12.
//

#ifndef MODULES_ISYSTEMUTILS_H
#define MODULES_ISYSTEMUTILS_H

#include "IModule.h"

namespace bdlbsc
{

    class ISystemUtils : public IModule
    {
        Q_OBJECT
    public:
        ~ISystemUtils() = 0;
    };

} // namespace bdlbsc

#endif //MODULES_ISYSTEMUTILS_H
