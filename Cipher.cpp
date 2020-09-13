//
// Created by Proprio on 2020-09-13.
//

#include "Cipher.h"

int Cipher::firstMinusLast(int a, int b) {

    int temp = a - b;
    if (temp >= 0)
        return temp;

    return ALPHABET_NUMBER + temp;

}
