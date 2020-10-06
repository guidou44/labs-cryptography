//
// Created by Proprio on 2020-10-05.
//

#include <Utils/BinaryUtil.h>
#include "ECBOperationMode.h"

using  namespace std;

std::string ECBOperationMode::encryptDecrypt(const std::string &targetText, const std::string &key) {
    vector<string> all7bitWords = separateIn7charsWords(targetText);
    string text;

    for (const auto& word : all7bitWords) {
        text += encryptDecryptInternal(word, key);
    }

    return text;
}

std::string ECBOperationMode::encryptDecryptInternal(const std::string &text, const std::string &key) {

    vector<bool> binaryText = BinaryUtil::getBinaryValues(text);
    vector<bool> binaryKey = BinaryUtil::getBinaryValues(key);
    vector<bool> resultBinary = BinaryUtil::XOR(binaryText, binaryKey);

    return BinaryUtil::getCharValues(resultBinary);
}

