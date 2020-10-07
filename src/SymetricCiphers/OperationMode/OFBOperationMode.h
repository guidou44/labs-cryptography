//
// Created by Proprio on 2020-10-06.
//

#ifndef CRYPTOGRAPHY_OFBOPERATIONMODE_H
#define CRYPTOGRAPHY_OFBOPERATIONMODE_H


#include "CFBOperationMode.h"

class OFBOperationMode : public CFBOperationMode {
protected:
    void prepareNextEncryptionInput(std::vector<bool>& nextEncryptionInput, const std::vector<bool>& blockResult,
                                            const std::vector<bool>& firstEncryptionResult,
                                            const std::vector<bool>& wordBinary, bool isEncrypting) override;
};


#endif //CRYPTOGRAPHY_OFBOPERATIONMODE_H
