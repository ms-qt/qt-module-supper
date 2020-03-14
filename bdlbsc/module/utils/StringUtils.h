//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_STRINGUTILS_H
#define MODULES_STRINGUTILS_H

#include <bdlbsc/module/supper/IStringUtils.h>
namespace bdlbsc
{

    class StringUtils : public IStringUtils
    {

    public:
        StringUtils();
        ~StringUtils();

        QString encoding(QString str) override;
        QString decoding(QString str) override;
    };

} // namespace bdlbsc

#endif //MODULES_STRINGUTILS_H
