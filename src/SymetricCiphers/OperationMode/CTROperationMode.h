//
// Created by Proprio on 2020-10-07.
//

#ifndef CRYPTOGRAPHY_CTROPERATIONMODE_H
#define CRYPTOGRAPHY_CTROPERATIONMODE_H


#include <string>
#include "OperationModeBase.h"

class CTROperationMode : protected OperationModeBase {

public:
    std::string encrypt(const std::string& text, const std::string& key, const std::string& iv);
    std::string decrypt(const std::string& text, const std::string& key);
private:
    static std::string encryptDecryptInternal(const std::string& text, const std::string& key, const std::string& iv);



};


#endif //CRYPTOGRAPHY_CTROPERATIONMODE_H
