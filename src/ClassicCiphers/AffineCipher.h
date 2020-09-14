//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_AFFINECIPHER_H
#define EX1_AFFINECIPHER_H


#include <string>
#include "Base/Cipher.h"

class AffineCipher : protected Cipher {

public:
    std::string encrypt(const std::string& clearMessage, int a, int b);
    std::string decrypt(const std::string& encrypted, int a, int b);

private:
    static int pgcd(int a, int b);
    int eulerFunction(int n);
};


#endif //EX1_AFFINECIPHER_H
