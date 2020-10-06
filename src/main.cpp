#include <iostream>
#include <SymetricCiphers/Vigenere/FreidmanTester.h>
#include <SymetricCiphers/OperationMode/ECBOperationMode.h>
#include <SymetricCiphers/OperationMode/CBCOperationMode.h>
#include "ClassicCiphers/AffineCipher.h"
#include "ClassicCiphers/SubstitutionCipher.h"
#include "ClassicCiphers/PolybeCipher.h"
#include "ClassicCiphers/PermutationCipher.h"
#include "ClassicCiphers/HillCipher.h"

void runVigenereTests();
void runEcbModeTest();
void runClassicCiphers();
void runCbcModeTest();

using namespace std;

int main() {

    //runClassicCiphers();
    //runVigenereTests();

    try {
        runEcbModeTest();
        runCbcModeTest();
    } catch (logic_error& ex) {
        cout << ex.what() << endl;
    }



    return 0;
}

void runVigenereTests() {
    string encryptedVigenere = "JEXCGQDUILIXXDIMXVNGXIBVPGLSMIUVVLZHPCQINXTOGFPWXMIFTXDVRWMCEKMIIAWZGBDWIYIJ"
                                    "MSRVWMJJRFRPZVIZRAJVSZRUMCXEJIMQPKMIIGPCPYYTARMHOIMKMHOSJEMHOIACMADFAVXYSX"
                                    "RRPFZHRZTBZVIVBNYIRICJOMDEMMOLTIIPZVHVMHJXWVVQJVSJQIQMCXJLJQIYIOIMCKIFGMVZFFZ"
                                    "GXGLYMXTOXVVGZKSJGEXEXYSXPTMJCIGZWUKEXISZVPVFVCOLBJXBVXRIIUOIIYIYIGGPTNDSCRRX"
                                    "OLTIIPZVHZRAYIRICJOMDEXBZHTKECGISFTYMEIZSHJJPTMJCIGZWWJRIISFGISSSNCFNKLYVPVFVCO"
                                    "LBRRXDRTRGBDRHKEHXIQPEEZCIYMMDWPJIWMIIZHYVPAPOHJACFRFTXDKLYXSBDYHDGPEXMPWJ"
                                    "RPFTEHYSLOWIIMHBSUTLUMERKILNAWZGBDWCVIXZHIFHYXVNGXNCIRZTBZVIVBNVGGPTNJWNJXY"
                                    "HMHKLYJVSVVYYPXJXIAIAVQYIXHFJZDRXKIJJWHZFFZTARMHOIMKWZDRXKIJJWHZFFZGNGLYMXT"
                                    "OXMAMCZXYKSHJMVGIZVCMVRSKLYZRRICJOMDEEHYHTTVSKXXFRUGKDIMNCQHNLCXLRFVLZWEF"
                                    "RXOSTRGBFINBISNEGVMGKSGKEHOEHTMJCIGJACOLDLXPVVXRFFZOTPWWVRQVXLDZXRPFTFGFOYI"
                                    "AXKLIIPNKLYFRDNPYYKTFJNCIRZTBZVJJIXVRSRVYOLTIIZJVTLWYGIHJSLZZTEGIPRIVVJMSSLGNDZT"
                                    "WSLHSHKTOMTDJIMCMHKSLDGPCPSXMEYILNATIIIAXTEYMZHSZVYXXAPJIMICTVSKXXFRIMHTTVSK"
                                    "XXFRQDXWFYNVHSZXCJRPCTLJGTUYLZWHLGBVWPLXBZRIZGUOMDESLDRIVKLDXNTLYXOH";

    FreidmanTester freidmanTester;

    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 1);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 2);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 3);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 4);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 5);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 6);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 7);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 8);
    freidmanTester.printAllCoincidenceIndexesForBlocksOfSize(encryptedVigenere, 9);
    cout << "-------------"<< endl;
    freidmanTester.printLetterFrequenciesEnglish();
    FreidmanTester::printAllStringBlockForSize(encryptedVigenere, 6);
    freidmanTester.printMaxLetterFrequencyInAllStringBlockFor(encryptedVigenere, 6);
}

void runClassicCiphers() {
    AffineCipher affine;
    std::string encrypted = "WNIIR PRAIK";
    std::string clear = "HELLO WORLD";
    std::cout << "--------- AFFINE CIPHER -----------" << std::endl;
    std::cout << encrypted << " decrypted to : "<< affine.decrypt(encrypted, 3, 1) <<std::endl;
    std::cout << clear << " encrypted to : "<< affine.encrypt(clear, 3, 1) <<std::endl;

    SubstitutionCipher substitutionCipher;
    std::string encrypted2 = "QSNQRFRSRFLK";
    std::string clear2 = "SUBSTITUTION";
    std::cout << "--------- SUBSTITUTION CIPHER -----------" << std::endl;
    std::cout << encrypted2 << " decrypted to : "<< substitutionCipher.decrypt(encrypted2) <<std::endl;
    std::cout << clear2 << " encrypted to : "<< substitutionCipher.encrypt(clear2) <<std::endl;

    PolybeCipher polybe("CRYPTANALYSE");
    std::string encrypted3 = "44211213241552211215";
    std::string clear3 = "MARYSTUART";
    std::cout << "--------- POLYBE CIPHER -----------" << std::endl;
    std::cout << std::endl << polybe << std::endl;
    std::cout << encrypted3 << " decrypted to : "<< polybe.decrypt(encrypted3) <<std::endl;
    std::cout << clear3 << " encrypted to : "<< polybe.encrypt(clear3) <<std::endl;

    PermutationCipher permutationCipher("321");
    std::string encrypted4 = "lecqiuaiutaletenadnusuofterseleipdsdsnafnugiresonesnetyomnnertebsenei";
    std::string clear4 = "celuiquialatetedansunfouretlespiedsdansunfrigosesentenmoyennetresbien";
    std::cout << "--------- PERMUTATION CIPHER -----------" << std::endl;
    std::cout << encrypted4 << " decrypted to : "<< permutationCipher.decrypt(encrypted4) <<std::endl;
    std::cout << clear4 << " encrypted to : "<< permutationCipher.encrypt(clear4) <<std::endl;

    std::vector<std::vector<int>> key = {{2, 1}, {1, 2}};
    HillCipher hillCipher(key);
    std::string encrypted5 = "YUNCNAQBEVTE";
    std::string clear5 = "SOIXANTENEUF";
    std::cout << "--------- HILL CIPHER -----------" << std::endl;
    std::cout << encrypted5 << " decrypted to : "<< hillCipher.decrypt(encrypted5) <<std::endl;
    std::cout << clear5 << " encrypted to : "<< hillCipher.encrypt(clear5) <<std::endl;
}

void runEcbModeTest() {
    ECBOperationMode ecb;
    string word = "10111110011001";
    string key = "1110101";
    cout<<"encrypting : " << word << " with key :" << key << endl;
    cout<<"result : " << ecb.encryptDecrypt(word, key) <<  endl;

    word = "11011111000001";
    key = "0110101";
    cout<<"decrypting : " << word << " with key :" << key << endl;
    cout<<"result : " << ecb.encryptDecrypt(word, key) <<  endl;

}

void runCbcModeTest() {
    CBCOperationMode cbc;
    string iv = CBCOperationMode::generateInitVector();
    string word = "11100011100111";
    string key = "1011111";
    iv = "1100111";

    cout<<"encrypting : " << word << " with key :" << key << "with IV : " << iv <<endl;
    cout<<"result : " << cbc.encrypt(word, key, iv) <<  endl;

    word = "110010100110011010101";
    key = "1001111";
    iv ="";

    cout<<"decrypting : " << word << " with key :" << key << "with IV : " << iv <<endl;
    cout<<"result : " << cbc.decrypt(word, key) <<  endl;
}
