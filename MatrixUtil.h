#include <utility>

//
// Created by Proprio on 2020-09-13.
//

#ifndef EX1_MATRIXUTIL_H
#define EX1_MATRIXUTIL_H
#define N 2

class MatrixUtil {
public:
    static std::vector<std::vector<int>> inverse2x2ModN(std::vector<std::vector<int>>& matrix, int moduloN);
    static std::vector<int> multiply2x2withArray(std::vector<std::vector<int>>& matrix, std::vector<int>& array);
private:
    static int determinant2x2(std::vector<std::vector<int>>& matrix);
    static std::vector<std::vector<int>> adjoint2x2(std::vector<std::vector<int>>& matrix);
    static int inverseInModulo(int inverseOf, int moduloN);

};


int MatrixUtil::determinant2x2(std::vector<std::vector<int>>& matrix)
{
    int det= 0;
    if (matrix.size() == 1 && matrix[0].size() == 1)
        return matrix[0][0];

    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    return det;
}

std::vector<std::vector<int>> MatrixUtil::adjoint2x2(std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> adjoint(N);
    adjoint[0] = std::vector<int>(N);
    adjoint[1] = std::vector<int>(N);
    adjoint[0][0] = matrix[1][1];
    adjoint[1][1] = matrix[0][0];
    adjoint[0][1] = -1*matrix[0][1];
    adjoint[1][0] = -1*matrix[1][0];
    return adjoint;
}

std::vector<std::vector<int>> MatrixUtil::inverse2x2ModN(std::vector<std::vector<int>>& matrix, int moduloN) {
    int det = determinant2x2(matrix);
    std::vector<std::vector<int>> adjoint = adjoint2x2(matrix);
    int detModuloN = inverseInModulo(det, moduloN);
    for (std::vector<int>& row : adjoint) {
        for (int & i : row) {
            i = (detModuloN * i) % 26;
        }
    }
    return adjoint;
}

int MatrixUtil::inverseInModulo(int inverseOf, int moduloN) {
    inverseOf = inverseOf % moduloN;
    for (int x=1; x < moduloN; x++)
        if ((inverseOf * x) % moduloN == 1)
            return x;
}

std::vector<int>
MatrixUtil::multiply2x2withArray(std::vector<std::vector<int>> &matrix, std::vector<int>& array) {
    if (array.size() != N || matrix.size() != N || matrix[0].size() != N || matrix[1].size() != N)
        throw std::logic_error("invalid matrix or array size");

    std::vector<int> result(N);

    result[0] = matrix[0][0]*array[0] + matrix[0][1]*array[1];
    result[1] = matrix[1][0]*array[0] + matrix[1][1]*array[1];
    return result;
}


#endif //EX1_MATRIXUTIL_H
