//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_POLYBECIPHER_H
#define EX1_POLYBECIPHER_H


#include <string>

class PolybeCipher {

public:
    PolybeCipher(std::string key);
    void setKey(const std::string& key);
    std::string encrypt(const std::string& clearMessage);
    std::string decrypt(const std::string& encrypted);

    friend std::ostream &operator<<(std::ostream &out, const PolybeCipher &c) {
        for (auto i : c.polybeSquare) {
            for (int j =0; j < 5; j++) {
                out << i[j];
            }
            out << std::endl;
        }
        return out;
    }



private:
    const int SQUARE_SIDE = 5;
    std::string secretKey;
    char polybeSquare[5][5] = {
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'J'},
            {'K', 'L', 'M', 'N', 'O'},
            {'P', 'Q', 'R', 'S', 'T'},
            {'U', 'V', 'X', 'Y', 'Z'},
    };
};


#endif //EX1_POLYBECIPHER_H
