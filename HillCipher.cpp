//
// Created by Proprio on 2020-09-13.
//

#include <iostream>
#include "HillCipher.h"
#include "MatrixUtil.h"

using namespace std;

std::string HillCipher::encrypt(const std::string &clearMessage) {
    return std::string();
}

std::string HillCipher::decrypt(const std::string &encrypted) {

    int test[2][2] = {{2, 1}, {1, 2}};
    float inv[2][2];

    MatrixUtil::inverse(test, inv);

    for (int i =0; i < 2; i++) {
        for (int j =0; j < 2; j++) {
            cout << inv[i][j] << " ";
        }
        cout << endl;
    }


    return std::string();
}
