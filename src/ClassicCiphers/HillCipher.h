//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_HILLCIPHER_H
#define EX1_HILLCIPHER_H
#define N 2

#include <vector>
#include "Base/Cipher.h"

class HillCipher : protected Cipher {

public:
    HillCipher(std::vector<std::vector<int>>  key);
    std::string encrypt(const std::string& clearMessage);
    std::string decrypt(const std::string& encrypted);

private:
    std::vector<std::vector<int>> matrixKey;
    static int customMod(int x, int m);
};


#endif //EX1_HILLCIPHER_H
