//
// Created by Proprio on 2020-09-13.
//

#include <iostream>
#include <sstream>
#include <utility>
#include "HillCipher.h"
#include "MatrixUtil.h"
#include "MapUtil.h"

using namespace std;

std::string HillCipher::encrypt(const std::string &clearMessage) {
    return std::string();
}

std::string HillCipher::decrypt(const std::string &encrypted) {
    std::ostringstream os;
    vector<vector<int>> inv = MatrixUtil::inverse2x2ModN(matrixKey, 26);
    for (int i=0; i < encrypted.size(); i += 2) {
        int firstVal = letterMapping[encrypted[i]];
        int secondVal = letterMapping[encrypted[i+1]];
        vector<int> arr = {firstVal, secondVal};
        vector<int> result = MatrixUtil::multiply2x2withArray(inv, arr);
        for (int& value : result) {
            value = value % 26;
            os << MapUtil::getMapKeyByValue(value, letterMapping);
        }
    }


    return os.str();
}

HillCipher::HillCipher(std::vector<std::vector<int>>  key) : matrixKey(std::move(key)) {

}
