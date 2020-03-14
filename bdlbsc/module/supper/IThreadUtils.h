//
// Created by 毛华伟 on 2020/3/12.
//

#ifndef MODULES_ITHREADUTILS_H
#define MODULES_ITHREADUTILS_H
#include <bdlbsc/module/supper/IModule.h>
#include <rxcpp/rx.hpp>


namespace bdlbsc
{

    class IThreadUtils : public IModule
    {
        Q_OBJECT
    public:
        virtual ~IThreadUtils() = 0;
        virtual void set_main_thread(rxcpp::observe_on_one_worker* worker) = 0;
        virtual rxcpp::observe_on_one_worker* get_main_thread() = 0;
    };

} // namespace bdlbsc

#endif //MODULES_ITHREADUTILS_H
