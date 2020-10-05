//
// Created by gdoucet on 03/10/2020.
//

#ifndef CRYPTOGRAPHY_FREIDMANTESTER_H
#define CRYPTOGRAPHY_FREIDMANTESTER_H


#include <map>
#include <string>
#include <list>

class FreidmanTester {

public:
    std::map<char, int> getCharCount(const std::string& text);
    std::map<char, double> getCharFrequency(const std::string& text);
    void printAllCoincidenceIndexesForBlocksOfSize(const std::string& text, int blockSize);
    void printLetterFrequenciesEnglish();
    static void printAllStringBlockForSize(const std::string& text, int blockSize);
    void printMaxLetterFrequencyInAllStringBlockFor(const std::string& text, int blockSize);

private:
    static std::list<std::string> getSubStringForBlockSize(const std::string& text, int blockSize);
    static double calculateIndexOfCoincidence(const std::map<char, int>& alphabetMap);
    void initializeAlphabetCharMap();
    void initializeAlphabetFrequencyMap();
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

    std::map<char, double> alphabetEnglishLetterFreq = {
            {'A', 8.2/100.0},
            {'B', 1.5/100.0},
            {'C', 2.8/100.0},
            {'D', 4.3/100.0},
            {'E', 13.0/100.0},
            {'F', 2.2/100.0},
            {'G', 2.0/100.0},
            {'H', 6.1/100.0},
            {'I', 7.0/100.0},
            {'J', 0.15/100.0},
            {'K', 0.77/100.0},
            {'L', 4.0/100.0},
            {'M', 2.4/100.0},
            {'N', 6.7/100.0},
            {'O', 7.5/100.0},
            {'P', 1.9/100.0},
            {'Q', 0.095/100.0},
            {'R', 6.0/100.0},
            {'S', 6.3/100.0},
            {'T', 9.1/100.0},
            {'U', 2.8/100.0},
            {'V', 0.98/100.0},
            {'W', 2.4/100.0},
            {'X', 0.15/100.0},
            {'Y', 2.0/100.0},
            {'Z', 0.074/100.0},
    };
};


#endif //CRYPTOGRAPHY_FREIDMANTESTER_H
