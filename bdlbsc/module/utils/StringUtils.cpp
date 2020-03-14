//
// Created by 毛华伟 on 2020/3/14.
//

#include "StringUtils.h"

namespace bdlbsc
{

    StringUtils::StringUtils()
    {
        initKv();
    }
    StringUtils::~StringUtils() {}

    void StringUtils::initKv()
    {
        memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
        memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);
    }

    QString StringUtils::encoding(QString str)
    {

        std::string cipherText;

        CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
        CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
        CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(cipherText));
        stfEncryptor.Put(reinterpret_cast<const unsigned char *>(str.toStdString().c_str()), str.toStdString().length() + 1);
        stfEncryptor.MessageEnd();

        std::string cipherTextHex;
        for (int i = 0; i < cipherText.size(); i++) {
            char ch[3] = { 0 };
            sprintf(ch, "%02x", static_cast<unsigned char>(cipherText[i]));
            cipherTextHex += ch;
        }
        return QString::fromStdString(cipherTextHex);
    }
    QString StringUtils::decoding(QString str)
    {

        std::string cipherText;
        std::string decryptedText;
        int i = 0;

        while (true) {
            char c;
            int x;
            std::stringstream ss;
            ss << std::hex << str.toStdString().substr(i, 2).c_str();
            ss >> x;
            c = (char)x;
            cipherText += c;
            if (i >= str.toStdString().length() - 2)
                break;
            i += 2;
        }
        CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
        CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);
        CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedText));
        stfDecryptor.Put(reinterpret_cast<const unsigned char *>(cipherText.c_str()), cipherText.size());

        stfDecryptor.MessageEnd();

        return QString::fromStdString(decryptedText);
    }

} // namespace bdlbsc