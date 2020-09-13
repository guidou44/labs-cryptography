//
// Created by Proprio on 2020-09-13.
//

#include <queue>
#include <iostream>
#include <sstream>
#include "PolybeCipher.h"
#include <algorithm>
#include <utility>
using namespace std;

void PolybeCipher::setKey(const std::string& key) {

    secretKey = key;
    queue<char> replacedLetters;
    vector<char> placedLetters;
    int lastIndex = 0;
    bool done = false;

    for (int j =0; j < SQUARE_SIDE; j++) {
        int columnIndex = 0;

        if (!done) {

            for (int i = 0; i< SQUARE_SIDE; i++) {

                if (lastIndex < key.size()) {
                    if (key.find(polybeSquare[j][i]) == std::string::npos)
                        replacedLetters.push(polybeSquare[j][i]);

                    while(std::find(placedLetters.begin(), placedLetters.end(), key[lastIndex]) != placedLetters.end()) {
                        lastIndex++;
                    }

                    if (lastIndex == key.size())
                        break;

                    polybeSquare[j][i] = key[lastIndex];
                    placedLetters.push_back(key[lastIndex]);
                    lastIndex++;
                }

                columnIndex++;
            }

            if (lastIndex == key.size())
                done = true;
        }

        if (done) {

            for (int i = columnIndex; i< SQUARE_SIDE; i++) {

                if (key.find(polybeSquare[j][i]) == std::string::npos)
                    replacedLetters.push(polybeSquare[j][i]);
                polybeSquare[j][i] = replacedLetters.front();
                replacedLetters.pop();
            }
        }

    }

}

std::string PolybeCipher::encrypt(const std::string& clearMessage) {

    std::ostringstream os;
    for (char letter : clearMessage) {
        for (int j = 0; j < SQUARE_SIDE; j++) {
            for (int i = 0; i < SQUARE_SIDE; i++) {
                if (letter == polybeSquare[j][i]) {
                    os << j+1 << i+1;
                }
            }
        }
    }

    return os.str();
}

std::string PolybeCipher::decrypt(const std::string& encrypted) {
    std::ostringstream os;

    for (int k = 0; k < encrypted.size(); k += 2) {
        int row = encrypted[k] - '0';
        int column = encrypted[k+1] - '0';

        for (int j = 1; j <= SQUARE_SIDE; j++) {
            for (int i = 1; i <= SQUARE_SIDE; i++) {
                if (j == row && i == column) {
                    os << polybeSquare[j-1][i-1];
                }
            }
        }
    }

    return os.str();
}

PolybeCipher::PolybeCipher(std::string key) {
    setKey(key);
}
