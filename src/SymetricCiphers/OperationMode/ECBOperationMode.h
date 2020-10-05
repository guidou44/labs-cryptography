//
// Created by Proprio on 2020-10-05.
//

#ifndef CRYPTOGRAPHY_ECBOPERATIONMODE_H
#define CRYPTOGRAPHY_ECBOPERATIONMODE_H


#include <string>

class ECBOperationMode {

public:
    std::string encrypt(const std::string& plainText, const std::string& key);
    std::string decrypt(const std::string& cipherText, const std::string& key);
};


#endif //CRYPTOGRAPHY_ECBOPERATIONMODE_H
