
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCE_FILES
        Utils/MatrixUtil.h
        ClassicCiphers/HillCipher.h
        Utils/BinaryUtil.cpp
        Utils/BinaryUtil.h
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
        SymetricCiphers/Vigenere/FreidmanTester.cpp
        SymetricCiphers/Vigenere/FreidmanTester.h
        SymetricCiphers/OperationMode/ECBOperationMode.cpp
        SymetricCiphers/OperationMode/ECBOperationMode.h
        SymetricCiphers/OperationMode/OperationModeBase.cpp
        SymetricCiphers/OperationMode/OperationModeBase.h
        SymetricCiphers/OperationMode/CBCOperationMode.cpp
        SymetricCiphers/OperationMode/CBCOperationMode.h
        SymetricCiphers/OperationMode/CFBOperationMode.cpp
        SymetricCiphers/OperationMode/CFBOperationMode.h
        main.cpp)


add_executable(Cryptography ${SOURCE_FILES})
add_library(${BINARY}_lib STATIC ${SOURCE_FILES})