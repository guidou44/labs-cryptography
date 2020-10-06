//
// Created by Proprio on 2020-10-05.
//

#ifndef CRYPTOGRAPHY_CBCOPERATIONMODE_H
#define CRYPTOGRAPHY_CBCOPERATIONMODE_H


#include "OperationModeBase.h"

class CBCOperationMode : protected OperationModeBase {

public:
    std::string encrypt(const std::string& text, const std::string& key, const std::string& iv);
    std::string decrypt(const std::string& text, const std::string& key);
    static std::string generateInitVector();
};


#endif //CRYPTOGRAPHY_CBCOPERATIONMODE_H
