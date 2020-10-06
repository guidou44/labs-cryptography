//
// Created by Proprio on 2020-10-05.
//

#ifndef CRYPTOGRAPHY_OPERATIONMODEBASE_H
#define CRYPTOGRAPHY_OPERATIONMODEBASE_H


#include <vector>
#include <string>

class OperationModeBase {

protected:
    std::vector<std::string> separateIn7charsWords(const std::string& text);
};


#endif //CRYPTOGRAPHY_OPERATIONMODEBASE_H
