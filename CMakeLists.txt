cmake_minimum_required(VERSION 3.15)
project(EX1)

set(CMAKE_CXX_STANDARD 14)

add_executable(EX1 main.cpp AffineCipher.cpp AffineCipher.h Cipher.cpp Cipher.h SubstitutionCipher.cpp SubstitutionCipher.h MapUtil.h PolybeCipher.cpp PolybeCipher.h PermutationCipher.cpp PermutationCipher.h HillCipher.cpp HillCipher.h MatrixUtil.h)