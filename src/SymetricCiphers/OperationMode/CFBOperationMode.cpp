//
// Created by Proprio on 2020-10-06.
//

#include <Utils/BinaryUtil.h>
#include "CFBOperationMode.h"
using namespace std;

std::string CFBOperationMode::encrypt(const std::string &text, const std::string &key, const std::string &iv, const int& r) {

    string cipherText = iv + encryptDecryptInternal(text, key, iv, r, true);
    return cipherText;
}

std::string CFBOperationMode::decrypt(const std::string &text, const std::string &key, const int& r) {
    vector<string> all7bitWords = separateInCharsWordsOfSize(text, BLOCK_SIZE);
    string iv = all7bitWords.at(0);

    return encryptDecryptInternal(text.substr(BLOCK_SIZE), key, iv, r, false);
}

std::string CFBOperationMode::encryptDecryptInternal(const std::string &text, const std::string &key, const std::string &iv,
                                                     const int &r, bool isEncrypting) {
    vector<string> allRbitWords = separateInCharsWordsOfSize(text, r);
    vector<bool> ivBinary = BinaryUtil::getBinaryValues(iv);
    vector<bool> keyBinary = BinaryUtil::getBinaryValues(key);
    vector<bool> encryptionInput = ivBinary;
    string outputText;

    for (const auto & allRbitWord : allRbitWords) {

        vector<bool> firstEncryptionOutput = BinaryUtil::XOR(encryptionInput, keyBinary);
        vector<bool> outputMRB(firstEncryptionOutput.begin(), firstEncryptionOutput.begin() + allRbitWord.size());
        vector<bool> wordBinary = BinaryUtil::getBinaryValues(allRbitWord);
        vector<bool> blockResult = BinaryUtil::XOR(outputMRB, wordBinary);
        outputText += BinaryUtil::getCharValues(blockResult);
        BinaryUtil::shiftLeft(encryptionInput, allRbitWord.size());
        prepareNextEncryptionInput(encryptionInput, blockResult, firstEncryptionOutput, wordBinary, isEncrypting);
    }

    return outputText;
}

void CFBOperationMode::appendBitsToNextInput(std::vector<bool> &nextEncryptionInput,
                                             const std::vector<bool> &bitsToAppend) {
    nextEncryptionInput.insert(nextEncryptionInput.end(), bitsToAppend.begin(), bitsToAppend.end());
}

void CFBOperationMode::prepareNextEncryptionInput(std::vector<bool> &nextEncryptionInput,
                                                  const std::vector<bool> &blockResult,
                                                  const std::vector<bool> &firstEncryptionResult,
                                                  const std::vector<bool> &wordBinary, bool isEncrypting) {
    if (isEncrypting)
        appendBitsToNextInput(nextEncryptionInput, blockResult);
    else
        appendBitsToNextInput(nextEncryptionInput, wordBinary);
}
