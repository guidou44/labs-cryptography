#include <iostream>
#include <SymetricCiphers/FreidmanTester.h>
#include "ClassicCiphers/AffineCipher.h"
#include "ClassicCiphers/SubstitutionCipher.h"
#include "ClassicCiphers/PolybeCipher.h"
#include "ClassicCiphers/PermutationCipher.h"
#include "ClassicCiphers/HillCipher.h"

using namespace std;

int main() {

    //runClassicCiphers();

    std::string encryptedVigenere = "JEXCGQDUILIXXDIMXVNGXIBVPGLSMIUVVLZHPCQINXTOGFPWXMIFTXDVRWMCEKMIIAWZGBDWIYIJ"
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
    map<char, int> frequencyMap = freidmanTester.getCharFrequency(encryptedVigenere);

   for (auto & it : frequencyMap) {
       cout << /*it.first << "  " <<*/ it.second << endl;
   }

    return 0;
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
