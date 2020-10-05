//
// Created by gdoucet on 03/10/2020.
//

#include <sstream>
#include <iostream>
#include "FreidmanTester.h"

using namespace std;

std::map<char, int> FreidmanTester::getCharCount(const std::string& text) {

    initializeAlphabetCharMap();

    for (char letter: text) {
        alphabetMap[letter] += 1;
    }

    return alphabetMap;
}

void FreidmanTester::initializeAlphabetCharMap() {
    alphabetMap = {
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

}

void FreidmanTester::initializeAlphabetFrequencyMap() {
    alphabetEnglishLetterFreq = {
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
}

void FreidmanTester::printAllCoincidenceIndexesForBlocksOfSize(const std::string &text, int blockSize) {

    ostringstream os;

    for (int i = 0; i < blockSize; i++) {
        string subString;
        for (int j = i; j < text.size(); j += blockSize) {
            subString += text[j];
        }

        map<char, int> freqMap = getCharCount(subString);
        os << " " << calculateIndexOfCoincidence(freqMap) << " ";
    }
    os << endl;
    cout << os.str();
}

double FreidmanTester::calculateIndexOfCoincidence(const std::map<char, int>& alphabetMap) {

    double indexOfCoincidenceNumerator = 0;
    int totalChars = 0;

    for (auto & it : alphabetMap) {
        int n = it.second;
        totalChars += n;
        indexOfCoincidenceNumerator += n*(n-1);
    }

    return indexOfCoincidenceNumerator / (totalChars * (totalChars-1));
}

void FreidmanTester::printLetterFrequenciesEnglish() {
    for (auto & it : alphabetEnglishLetterFreq) {
       cout << it.second << endl;
    }

}

void FreidmanTester::printAllStringBlockForSize(const std::string &text, int blockSize) {
    ostringstream os;
    int total = 0;

    list<string> allSubs = getSubStringForBlockSize(text, blockSize);

    for (const auto& it : allSubs) {
        total += it.size();
        os << it << endl;
        os << "----------------" << endl;
    }

    os << "totalchars: " << total << endl;

    cout << os.str();
}

std::list<std::string> FreidmanTester::getSubStringForBlockSize(const std::string& text, int blockSize) {
    std::list<std::string> allSubStrings;

    for (int i = 0; i < blockSize; i++) {
        string subString;
        for (int j = i; j < text.size(); j += blockSize) {
            subString += text[j];
        }

        allSubStrings.push_back(subString);
    }

    return allSubStrings;
}

void FreidmanTester::printMaxLetterFrequencyInAllStringBlockFor(const std::string &text, int blockSize) {
    list<string> allSubs = getSubStringForBlockSize(text, blockSize);

    int count = 0;
    for (const auto& sub : allSubs) {
        cout << "Y" << count << " : " << endl;
        map<char, double> letterFreq = getCharFrequency(sub);
        double max = 0;
        char maxChar = '*';
        for (auto & it : letterFreq) {
            if (it.second > max) {
                max = it.second;
                maxChar = it.first;
            }

            cout << it.first  << " : " << it.second <<endl;
        }

        cout << maxChar << " : " << max << endl;
        cout << "----------------" << endl;

        count++;
    }

}

std::map<char, double> FreidmanTester::getCharFrequency(const std::string &text) {
    map<char, int> charCount = getCharCount(text);
    initializeAlphabetFrequencyMap();

    for (auto & it : charCount) {
        double freqTop = (double)it.second;
        double freqBottom = (double)text.size();
        alphabetEnglishLetterFreq[it.first] = freqTop / freqBottom;
    }

    return alphabetEnglishLetterFreq;
}


