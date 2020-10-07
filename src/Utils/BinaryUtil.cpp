//
// Created by Proprio on 2020-10-06.
//

#include "BinaryUtil.h"


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

void BinaryUtil::shiftLeft(std::vector<bool> &target, int numberOfBits) {
    target.erase(target.begin(), target.begin() + numberOfBits);
}

void BinaryUtil::incrementInModuloN(std::vector<bool> &target) {

    unsigned int lastTargetIndex = target.size() - 1;
    for (unsigned int i = lastTargetIndex; i >= 0; i--) {
        if (!target[i] && i == lastTargetIndex) {
            target[i] = true;
            return;//LSB est à 0, on incrémente et on retourne.
        }

        if (!target[i]) {
            target[i] = true;
            target[i+1] = false;
            return; //Premier bit à 0 rencontré (autre que le bit moins significatif) est mis à 1, et son bit de droite est remis à 0.
        }
    }

    //Si on se rend ici, tout les bits sont des 1, donc on remet tout à 0 pour rester dans modulo n où n est le nombre de bit.
    for  (auto && i : target) {
        i = false;
    }
}


//region private methods

bool BinaryUtil::charIsBit(const char &c) {
    if (!std::isdigit(c))
        return false;
    int digit = c - '0';
    return !(digit != 0 && digit != 1);
}

bool BinaryUtil::getBinaryValue(const char &c) {
    if (!charIsBit(c))
        throw std::logic_error("char does not represent bit");

    int digit = c - '0';
    return digit == 1;
}

char BinaryUtil::getCharRepresentation(bool bit) {
    return (bit) ? '1' : '0';
}

//endregion

