//
// Created by 毛华伟 on 2020/3/14.
//

#include "UUIDUtils.h"

namespace bdlbsc
{

    UUIDUtils::UUIDUtils() {}
    UUIDUtils::~UUIDUtils() {}

    QString UUIDUtils::uuid()
    {
        return QUuid::createUuid().toString();
    }

} // namespace bdlbsc