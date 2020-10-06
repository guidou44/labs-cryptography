//
// Created by Proprio on 2020-10-06.
//

#ifndef CRYPTOGRAPHY_CFBOPERATIONMODE_H
#define CRYPTOGRAPHY_CFBOPERATIONMODE_H


#include "OperationModeBase.h"

class CFBOperationMode : protected OperationModeBase {

public:
    static std::string encrypt(const std::string& text, const std::string& key, const std::string& iv, const int& r);
    static std::string decrypt(const std::string& text, const std::string& key, const int& r);
private:
    static std::string encryptDecryptInternal(const std::string& text, const std::string& key, const std::string& iv, const int& r, bool isEncrypting);
};


#endif //CRYPTOGRAPHY_CFBOPERATIONMODE_H
