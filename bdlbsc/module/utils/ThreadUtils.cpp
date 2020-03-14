//
// Created by 毛华伟 on 2020/3/14.
//

#include "ThreadUtils.h"

namespace bdlbsc
{

    ThreadUtils::ThreadUtils()
    {
        _main_thread = nullptr;
    }
    ThreadUtils::~ThreadUtils() {}

    void ThreadUtils::set_main_thread(rxcpp::observe_on_one_worker *worker)
    {
        _main_thread = worker;
    }
    rxcpp::observe_on_one_worker *ThreadUtils::get_main_thread()
    {
        return _main_thread;
    }

} // namespace bdlbsc