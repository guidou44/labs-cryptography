//
// Created by Proprio on 2020-10-05.
//

#ifndef CRYPTOGRAPHY_OPERATIONMODEBASE_H
#define CRYPTOGRAPHY_OPERATIONMODEBASE_H


#include <vector>
#include <string>

class OperationModeBase {

protected:
    static const int BLOCK_SIZE = 7;
    static std::vector<std::string> separateInCharsWordsOfSize(const std::string& text, int size);
public:
    static std::string generateInitVector();
    static int getRandomRParameter(int max);
};


#endif //CRYPTOGRAPHY_OPERATIONMODEBASE_H
