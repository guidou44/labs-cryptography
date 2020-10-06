//
// Created by Proprio on 2020-10-05.
//

#include "OperationModeBase.h"

std::vector<std::string> OperationModeBase::separateIn7charsWords(const std::string &text) {
    int wordCount = text.size() / 7;
    std::vector<std::string> output;

    for (int i=0; i < wordCount; i++) {
        if (i == wordCount - 1)
            output.push_back(text.substr(i*7));
        else
            output.push_back(text.substr(i*7, 7));
    }
    return output;
}
