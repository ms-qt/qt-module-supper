//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_THREADUTILS_H
#define MODULES_THREADUTILS_H

#include <bdlbsc/module/supper/IThreadUtils.h>

namespace bdlbsc
{
    class ThreadUtils : public IThreadUtils
    {
    public:
        ThreadUtils();
        ~ThreadUtils();
        rxcpp::observe_on_one_worker* _main_thread;
        void set_main_thread(rxcpp::observe_on_one_worker *worker) override;
        rxcpp::observe_on_one_worker* get_main_thread() override;
    };
} // namespace bdlbsc
#endif //MODULES_THREADUTILS_H
