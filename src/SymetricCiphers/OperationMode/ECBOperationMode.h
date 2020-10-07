//
// Created by Proprio on 2020-10-05.
//

#ifndef CRYPTOGRAPHY_ECBOPERATIONMODE_H
#define CRYPTOGRAPHY_ECBOPERATIONMODE_H


#include <string>
#include "OperationModeBase.h"

class ECBOperationMode : protected OperationModeBase {

public:
    std::string encryptDecrypt(const std::string& targetText, const std::string& key);
private:
    std::string encryptDecryptInternal(const std::string& text, const std::string& key);
};


#endif //CRYPTOGRAPHY_ECBOPERATIONMODE_H
