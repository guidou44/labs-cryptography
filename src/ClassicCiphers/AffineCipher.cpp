//
// Created by Proprio on 2020-09-13.
//

#include "AffineCipher.h"
#include "../Utils/MapUtil.h"
#include <math.h>

using namespace std;

std::string AffineCipher::decrypt(const std::string& encrypted, int a, int b) {
    //ax+b%26
    string clearMessage;

    int eulerOf26 = eulerFunction(ALPHABET_NUMBER);
    int temp = pow(a, eulerOf26 - 1);
    int inverseOfAInZ26 = temp % ALPHABET_NUMBER;
    for (char letter : encrypted) {
        if (letter == ' ')
            clearMessage += letter;
        else {
            int eqNumber = letterMapping[letter];
            int clearNumber = firstMinusLast(eqNumber, b) * inverseOfAInZ26 % ALPHABET_NUMBER;
            char clearLetter = MapUtil::getMapKeyByValue<char, int>(clearNumber, letterMapping);
            clearMessage += clearLetter;
        }
    }

    return clearMessage;
}

std::string AffineCipher::encrypt(const std::string& clearMessage, int a, int b) {

    string encrypted;

    for (char letter : clearMessage) {
        if (letter == ' ')
            encrypted += letter;
        else {
            int eqNumber = letterMapping[letter];
            int eNumber = a * eqNumber + b % ALPHABET_NUMBER;
            while (eNumber >= ALPHABET_NUMBER)
                eNumber -= ALPHABET_NUMBER;
            char encryptedLetter = MapUtil::getMapKeyByValue<char, int>(eNumber, letterMapping);
            encrypted += encryptedLetter;
        }
    }

    return encrypted;
}

int AffineCipher::pgcd(int a, int b) {
    if (a == 0)
        return b;
    return pgcd(b % a, a);
}

int AffineCipher::eulerFunction(int n) {
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (pgcd(i, n) == 1)
            result++;
    return result;
}
