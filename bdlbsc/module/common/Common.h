//
// Created by dev on 2020/3/12.
//

#ifndef MODULES_COMMON_H
#define MODULES_COMMON_H
#include <QtCore/QObject>
#include <bdlbsc/module/data/Data.h>
namespace bdlbsc {
    class Common : public QObject {
        Q_OBJECT
    public:
        Common();
        ~Common();

        // 获取data
        static bdlbsc::Data getData();
    };
}// namespace bdlbsc

#endif//MODULES_COMMON_H
