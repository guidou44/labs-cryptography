//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_SUBSTITUTIONCIPHER_H
#define EX1_SUBSTITUTIONCIPHER_H


#include "Cipher.h"

class SubstitutionCipher : protected Cipher {

public:
    std::string encrypt(const std::string& clearMessage);
    std::string decrypt(const std::string& encrypted);

private:
    std::map<int, int> key = {
            {0, 20},
            {1, 13},
            {2, 21},
            {3, 0},
            {4, 1},
            {5, 2},
            {6, 3},
            {7, 4},
            {8, 5},
            {9, 6},
            {10, 7},
            {11, 8},
            {12, 9},
            {13, 10},
            {14, 11},
            {15, 12},
            {16, 14},
            {17, 15},
            {18, 16},
            {19, 17},
            {20, 18},
            {21, 19},
            {22, 22},
            {23, 23},
            {24, 24},
            {25, 25},
    };
};


#endif //EX1_SUBSTITUTIONCIPHER_H
