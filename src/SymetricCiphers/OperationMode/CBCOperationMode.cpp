//
// Created by Proprio on 2020-10-05.
//

#include <bitset>
#include <Utils/BinaryUtil.h>
#include "CBCOperationMode.h"
using namespace std;

std::string CBCOperationMode::encrypt(const std::string &text, const std::string &key, const std::string &iv) {
    vector<string> all7bitWords = separateInCharsWordsOfSize(text, BLOCK_SIZE);
    vector<bool> keyBinary = BinaryUtil::getBinaryValues(key);
    vector<bool> ivBinary = BinaryUtil::getBinaryValues(iv);
    string cipherText = iv;
    vector<vector<bool>> resultsBinary;

    for (int i = 0; i < all7bitWords.size(); i++) {
        vector<bool> temp;
        vector<bool> binaryWord = BinaryUtil::getBinaryValues(all7bitWords[i]);
        if (i == 0) {
            temp = BinaryUtil::XOR(binaryWord, ivBinary);
        } else {
            temp = BinaryUtil::XOR(binaryWord, resultsBinary[i - 1]);
        }

        vector<bool> result = BinaryUtil::XOR(keyBinary, temp);
        resultsBinary.push_back(result);
        cipherText += BinaryUtil::getCharValues(result);
    }

    return cipherText;
}

std::string CBCOperationMode::decrypt(const std::string &text, const std::string &key) {
    vector<string> all7bitWords = separateInCharsWordsOfSize(text, BLOCK_SIZE);
    if (all7bitWords.size() == 1)
        throw logic_error("cannot decrypt word with only 1 7bits block with CBC");
    const string iv = all7bitWords.at(0);
    vector<bool> keyBinary = BinaryUtil::getBinaryValues(key);
    vector<bool> ivBinary = BinaryUtil::getBinaryValues(iv);
    string plainText;
    vector<vector<bool>> ciphersBinary;
    ciphersBinary.push_back(ivBinary);

    for (int i = 1; i < all7bitWords.size(); i++) {
        vector<bool> result;
        vector<bool> binaryWord = BinaryUtil::getBinaryValues(all7bitWords[i]);
        ciphersBinary.push_back(binaryWord);

        vector<bool> temp = BinaryUtil::XOR(binaryWord, keyBinary);
        if (i == 1) {
            result = BinaryUtil::XOR(temp, ivBinary);
        } else {
            result = BinaryUtil::XOR(temp, ciphersBinary[i - 1]);
        }

        plainText += BinaryUtil::getCharValues(result);
    }

    return plainText;
}

