//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef MODULES_IUUIDUTILS_H
#define MODULES_IUUIDUTILS_H
#include "IModule.h"

namespace bdlbsc
{
    class IUUIDUtils : public IModule
    {
        Q_OBJECT
    public:
        virtual ~IUUIDUtils() = 0;
        virtual QString uuid() = 0;
    };

} // namespace bdlbsc

#endif //MODULES_IUUIDUTILS_H
