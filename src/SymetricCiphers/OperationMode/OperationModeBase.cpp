//
// Created by Proprio on 2020-10-05.
//

#include <bitset>
#include "OperationModeBase.h"

std::vector<std::string> OperationModeBase::separateInCharsWordsOfSize(const std::string &text, int size) {
    std::vector<std::string> output;

    std::string current;
    for (int i=0; i < text.size(); i++) {
        if (i % size == 0 && i != 0) {
            output.push_back(current);
            current.clear();
        }
        current += text[i];
    }

    output.push_back(current);
    return output;
}


std::string OperationModeBase::generateInitVector() {
    int iv = rand() % 128;
    std::string binary = std::bitset<7>(iv).to_string();
    return binary;
}

int OperationModeBase::getRandomRParameter(int max) {
    return (rand() % max) + 1;
}
