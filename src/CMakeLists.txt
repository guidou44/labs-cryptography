
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCE_FILES
        Utils/MatrixUtil.h
        ClassicCiphers/HillCipher.h
        ClassicCiphers/HillCipher.cpp
        ClassicCiphers/PermutationCipher.h
        ClassicCiphers/PermutationCipher.cpp
        ClassicCiphers/PolybeCipher.h
        ClassicCiphers/PolybeCipher.h
        ClassicCiphers/PolybeCipher.cpp
        Utils/MapUtil.h
        ClassicCiphers/SubstitutionCipher.h
        ClassicCiphers/SubstitutionCipher.cpp
        ClassicCiphers/Base/Cipher.h
        ClassicCiphers/Base/Cipher.cpp
        ClassicCiphers/AffineCipher.h
        ClassicCiphers/AffineCipher.cpp
        SymetricCiphers/FreidmanTester.cpp
        SymetricCiphers/FreidmanTester.h
        main.cpp)


add_executable(Cryptography ${SOURCE_FILES})
add_library(${BINARY}_lib STATIC ${SOURCE_FILES})