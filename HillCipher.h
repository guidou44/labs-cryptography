//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_HILLCIPHER_H
#define EX1_HILLCIPHER_H
#define N 2

#include <vector>
#include "Cipher.h"

class HillCipher : protected Cipher {

public:
    std::string encrypt(const std::string& clearMessage);
    std::string decrypt(const std::string& encrypted);

private:
    int matrixKey[N][N];
};


#endif //EX1_HILLCIPHER_H
