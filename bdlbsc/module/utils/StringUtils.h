//
// Created by 毛华伟 on 2020/3/14.
//

#ifndef MODULES_STRINGUTILS_H
#define MODULES_STRINGUTILS_H

#include <bdlbsc/module/supper/IStringUtils.h>
#include <cryptopp/aes.h>
#include <cryptopp/config.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <cryptopp/pch.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>

namespace bdlbsc
{

    class StringUtils : public IStringUtils
    {

    public:
        StringUtils();
        ~StringUtils();

        QString encoding(QString str) override;
        QString decoding(QString str) override;

    private:
        unsigned char key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
        void initKv();
    };

} // namespace bdlbsc

#endif //MODULES_STRINGUTILS_H
