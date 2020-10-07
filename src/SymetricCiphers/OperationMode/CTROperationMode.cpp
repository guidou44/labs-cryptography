//
// Created by Proprio on 2020-10-07.
//

#include <Utils/BinaryUtil.h>
#include "CTROperationMode.h"
using namespace std;

std::string CTROperationMode::encrypt(const std::string &text, const std::string &key, const std::string &iv) {
    string cipherText = iv + encryptDecryptInternal(text, key, iv);
    return cipherText;
}

std::string CTROperationMode::decrypt(const std::string &text, const std::string &key) {
    vector<string> all7bitWords = separateInCharsWordsOfSize(text, BLOCK_SIZE);
    string iv = all7bitWords.at(0);

    return encryptDecryptInternal(text.substr(BLOCK_SIZE), key, iv);
}

std::string
CTROperationMode::encryptDecryptInternal(const std::string &text, const std::string &key, const std::string &iv) {
    vector<string> all7bitWords = separateInCharsWordsOfSize(text, BLOCK_SIZE);
    vector<bool> keyBinary = BinaryUtil::getBinaryValues(key);
    vector<bool> ivBinary = BinaryUtil::getBinaryValues(iv);
    string resultText;

    for (const auto & all7bitWord : all7bitWords) {
        vector<bool> temp;
        vector<bool> binaryWord = BinaryUtil::getBinaryValues(all7bitWord);
        temp = BinaryUtil::XOR(ivBinary, keyBinary);
        vector<bool> result = BinaryUtil::XOR(binaryWord, temp);
        resultText += BinaryUtil::getCharValues(result);
        BinaryUtil::incrementInModuloN(ivBinary);
    }

    return resultText;
}
