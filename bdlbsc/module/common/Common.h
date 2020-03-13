//
// Created by dev on 2020/3/12.
//

#ifndef MODULES_COMMON_H
#define MODULES_COMMON_H
#include <QtCore/QObject>
#include <bdlbsc/module/common/Modules.h>
#include <bdlbsc/module/data/Data.h>


// 组件初始化
// 单例设计
namespace bdlbsc
{
    class Common : public QObject
    {
        Q_OBJECT
    public:
        static Common *get_instance();
        void init_log();
        Modules *get_modules();

    private:
        Common();
        ~Common();
        Modules *modules;
        static Common *instance;
    };
} // namespace bdlbsc

#endif //MODULES_COMMON_H
