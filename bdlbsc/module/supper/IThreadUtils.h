//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef MODULES_ITHREADUTILS_H
#define MODULES_ITHREADUTILS_H
#include <bdlbsc/module/supper/IModule.h>

namespace bdlbsc
{

    class IThreadUtils : public IModule
    {
    Q_OBJECT
    public:
        virtual ~IThreadUtils() = 0;
    };

} // namespace bdlbsc

#endif //MODULES_ITHREADUTILS_H
