//
// Created by Proprio on 2020-09-13.
//
#include<cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include "PermutationCipher.h"
using namespace std;

PermutationCipher::PermutationCipher(const std::string &key) {
    setPermutationKey(key);
}

void PermutationCipher::setPermutationKey(const std::string & key) {
    permutationkey.clear();
    vector<int> keyValues;
    for (int i = 1; i <= key.size(); i++) {
        char c = key[i-1];
        if (!isdigit(c)) {
            string error = "this is not a number : ";
            error.append(1, c);
            throw logic_error(error);
        }

        int correspondingNumber = c - '0';
        permutationkey[i] = correspondingNumber;
        keyValues.push_back(correspondingNumber);
    }

    keyMaxValue = *max_element(keyValues.begin(), keyValues.end());
}

std::string PermutationCipher::encrypt(const std::string &clearMessage) {
    ostringstream os;
    int currentSubStrIndex = 0;
    for (int i = 1; i <= clearMessage.size(); i++) {
        if (clearMessage[i-1] == ' ')
            os << clearMessage[i-1];
        else {
            int temp = i % keyMaxValue;
            temp = temp == 0 ? keyMaxValue : temp;
            int permIndex = permutationkey[temp];

            string currentSubString = getNextSubStr(currentSubStrIndex, clearMessage);
            os << currentSubString[permIndex-1];

            if (temp == keyMaxValue)
                currentSubStrIndex += keyMaxValue;
        }
    }

    return os.str();
}

std::string PermutationCipher::decrypt(const std::string &encrypted) {

    int currentSubStrIndex = 0;
    std::string clearMessage(encrypted.size(), '*');
    for (int i = 1; i <= encrypted.size(); i++) {
        if (encrypted[i-1] == ' ')
            clearMessage[i-1] = encrypted[i-1];
        else {
            int temp = i % keyMaxValue;
            temp = temp == 0 ? keyMaxValue : temp;
            int permIndex = permutationkey[temp];

            string currentSubString = getNextSubStr(currentSubStrIndex, encrypted);
            clearMessage[i-1] = currentSubString[permIndex-1];

            if (temp == keyMaxValue)
                currentSubStrIndex += keyMaxValue;
        }
    }

    return clearMessage;
}

std::string PermutationCipher::getNextSubStr(int &lastIndex, const std::string& word) const {
    string currentSubString;
    if (lastIndex + keyMaxValue < word.size()) {
        currentSubString = word.substr(lastIndex, keyMaxValue);
    }
    else
        currentSubString = word.substr(lastIndex);

    return  currentSubString;
}


void PermutationCipher::setKey(const std::string &key) {
    setPermutationKey(key);
}


