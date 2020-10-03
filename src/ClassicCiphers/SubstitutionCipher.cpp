//
// Created by Proprio on 2020-09-13.
//

#include <string>
#include "SubstitutionCipher.h"
#include "../Utils/MapUtil.h"

using namespace std;

std::string SubstitutionCipher::encrypt(const std::string& clearMessage) {
    string encrypted;

    for (char letter : clearMessage) {
        if (letter == ' ')
            encrypted += letter;
        else {
            int eqNumber = letterMapping[letter];
            int newVal = key[eqNumber];
            char eLetter = MapUtil::getMapKeyByValue<char, int>(newVal, letterMapping);
            encrypted += eLetter;
        }
    }

    return encrypted;
}

std::string SubstitutionCipher::decrypt(const std::string& encrypted) {
    string clearMessage;

    for (char letter : encrypted) {
        if (letter == ' ')
            clearMessage += letter;
        else {
            int eqNumber = letterMapping[letter];
            int newVal = MapUtil::getMapKeyByValue<int, int>(eqNumber, key);
            char dLetter = MapUtil::getMapKeyByValue<char, int>(newVal, letterMapping);
            clearMessage += dLetter;
        }
    }

    return clearMessage;
}
