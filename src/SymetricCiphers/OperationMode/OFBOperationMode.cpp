//
// Created by Proprio on 2020-10-06.
//

#include <Utils/BinaryUtil.h>
#include "OFBOperationMode.h"
using namespace std;

void OFBOperationMode::prepareNextEncryptionInput(std::vector<bool> &nextEncryptionInput,
                                                  const std::vector<bool> &blockResult,
                                                  const std::vector<bool> &firstEncryptionResult,
                                                  const std::vector<bool> &wordBinary, bool isEncrypting) {
    nextEncryptionInput = firstEncryptionResult;
}
