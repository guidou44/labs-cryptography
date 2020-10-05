//
// Created by Proprio on 2020-10-05.
//

#ifndef CRYPTOGRAPHY_BINARYUTIL_H
#define CRYPTOGRAPHY_BINARYUTIL_H

#include <string>
#include <stdexcept>
#include <vector>

class BinaryUtil {
public:
    static bool textIsBinaryNumbers(const std::string& text);
    static std::vector<bool> getBinaryValues(const std::string& binaryText);
    static std::string getCharValues(const std::vector<bool>& boolValues);
    static std::vector<bool> XOR(const std::vector<bool>& first, const std::vector<bool>& second);

private:
    static bool charIsBit(const char& c);
    static bool getBinaryValue(const char& c);
    static char getCharRepresentation(bool bit);

};

bool BinaryUtil::textIsBinaryNumbers(const std::string &text) {
    for (const auto& c : text) {
        if (!charIsBit(c))
            return false;
    }
    return true;
}

std::vector<bool> BinaryUtil::getBinaryValues(const std::string &binaryText) {
    if (!textIsBinaryNumbers(binaryText))
        throw std::logic_error("text is not binary number");

    std::vector<bool> binaryValues;

    for (const auto& c : binaryText) {
        binaryValues.push_back(getBinaryValue(c));
    }

    return binaryValues;
}

std::string BinaryUtil::getCharValues(const std::vector<bool>& boolValues) {
    std::string output;

    for (const auto& val : boolValues) {
        output += getCharRepresentation(val);
    }

    return output;
}

std::vector<bool> BinaryUtil::XOR(const std::vector<bool> &first, const std::vector<bool> &second) {
    if (first.size() != second.size())
        throw std::logic_error("comparison of different size not supported");
    std::vector<bool> result;

    for (int i=0; i < first.size(); i++) {
        result.push_back(first[i] ^ second[i]);
    }

    return result;
}

//region private methods

bool BinaryUtil::charIsBit(const char &c) {
    if (!std::isdigit(c))
        return false;
    int digit = std::atoi(&c);
    return !(digit != 0 && digit != 1);
}

bool BinaryUtil::getBinaryValue(const char &c) {
    if (!charIsBit(c))
        throw std::logic_error("char does not represent bit");

    int digit = std::atoi(&c);
    return digit == 1;
}

char BinaryUtil::getCharRepresentation(bool bit) {
    return (bit) ? '1' : '0';
}


//endregion

#endif //CRYPTOGRAPHY_BINARYUTIL_H
