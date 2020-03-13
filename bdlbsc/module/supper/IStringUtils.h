//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef MODULES_ISTRINGUTILS_H
#define MODULES_ISTRINGUTILS_H

#include <QObject>

#include <bdlbsc/module/supper/IModule.h>
namespace bdlbsc
{
    class IStringUtils : public IModule
    {
        Q_OBJECT
    public:
        virtual ~IStringUtils() = 0;
    };

} // namespace bdlbsc

#endif //MODULES_ISTRINGUTILS_H
