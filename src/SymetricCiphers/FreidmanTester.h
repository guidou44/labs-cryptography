//
// Created by gdoucet on 03/10/2020.
//

#ifndef CRYPTOGRAPHY_FREIDMANTESTER_H
#define CRYPTOGRAPHY_FREIDMANTESTER_H


#include <map>
#include <string>

class FreidmanTester {

public:
    std::map<char, int> getCharFrequency(const std::string& text);

private:
    void initializeAlphabetCharMap();
    std::map<char, int> alphabetMap = {
            {'A', 0},
            {'B', 0},
            {'C', 0},
            {'D', 0},
            {'E', 0},
            {'F', 0},
            {'G', 0},
            {'H', 0},
            {'I', 0},
            {'J', 0},
            {'K', 0},
            {'L', 0},
            {'M', 0},
            {'N', 0},
            {'O', 0},
            {'P', 0},
            {'Q', 0},
            {'R', 0},
            {'S', 0},
            {'T', 0},
            {'U', 0},
            {'V', 0},
            {'W', 0},
            {'X', 0},
            {'Y', 0},
            {'Z', 0},
    };
};


#endif //CRYPTOGRAPHY_FREIDMANTESTER_H
