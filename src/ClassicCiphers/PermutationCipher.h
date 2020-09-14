//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_PERMUTATIONCIPHER_H
#define EX1_PERMUTATIONCIPHER_H


#include "Base/Cipher.h"

class PermutationCipher : protected Cipher {

public:
    PermutationCipher(const std::string& key);
    std::string encrypt(const std::string& clearMessage);
    std::string decrypt(const std::string& encrypted);
    void setKey(const std::string& key);

private:
    void setPermutationKey(const std::string& key);
    std::string getNextSubStr(int& lastIndex, const std::string& word);
    std::map<int, int> permutationkey;
    int keyMaxValue;
};


#endif //EX1_PERMUTATIONCIPHER_H
