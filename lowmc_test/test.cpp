// Modified by Yuseong and Jihun

#include "LowMC.h"
#include <iostream>
#include <cstring>
#include <bitset>


//////////////////
//     MAIN     //
//////////////////

int main () {
    keyblock key;
    std::string string_key;
    std::cin >> string_key;
    if(string_key.length() == keysize) {
        key = (keyblock) string_key;
    } else {
        std::cout << "The entered key's length is different from the keysize. " << std::endl;
        return 0;
    }
    LowMC cipher(key);
    block m;
    std::string string_m;
    std::cin >> string_m;
    if(string_m.length() == blocksize) {
        m = (block) string_m;
    } else {
        std::cout << "The entered block's length is different from the blocksize. " << std::endl;
        return 0;
    }

    // std::cout << "Plaintext:" << std::endl;
    // std::cout << m << std::endl;
    m = cipher.encrypt( m );
    // std::cout << "Ciphertext:" << std::endl;
    std::cout << m << std::endl;
    // m = cipher.decrypt( m );
    // std::cout << "Encryption followed by decryption of plaintext:" << std::endl;
    // std::cout << m << std::endl;
   
    return 0;
}
