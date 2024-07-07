#include <operations.h>
#include <DES.h>
#include <string>
#include <vector>
#include <iostream>

int main() {
	//std::string key1, key2, key3;
	//std::string key = "1010101010111011000010010001100000100111001101101100110011011101";
	//key = key+key+key;
 //   key1 = key.substr(0, 64);
 //   key2 = key.substr(64, 64);
 //   key3 = key.substr(128, 64);
 //   std::vector<std::string> rkeys1, rkeys2, rkeys3;
	//rkeys1 = generateKeys(key1);
	//rkeys2 = generateKeys(key2);
	//rkeys3 = generateKeys(key3);

	//std::string pt = "1010101111001101111001101010101111001101000100110010010100110110";
	//std::cout << "Plain text: " << pt << std::endl;
	//std::string ct = TDES("E", rkeys1, rkeys2, rkeys3, pt);
	//std::cout << "Cipher text: " << ct << std::endl;

	//if (ct == "1001111000100110100111110101101011111010010011011011101101110000") {
	//	std::cout << "Plain text encrypted successfully." << std::endl;
	//}
	//else {
	//	std::cout << "Plain text encryption failed." << std::endl;

	//}

	//std::string plaintext = TDES("D", rkeys1, rkeys2, rkeys3, ct);
	//std::cout << "Decrypted ciphertext: " << plaintext << std::endl; 
	//if(plaintext==pt) {
	//	std::cout << "ciphertext decrypted successfully." << std::endl;
	//}

	std::string pt = "nigger";
	std::cout << pt << std::endl;
	std::string binary = asciiToBinary(pt);
	std::cout << binary << std::endl;
	std::string converted = binaryToAscii(binary);
	std::cout << converted << std::endl;
	if (converted == pt) {
		std::cout << "text converted" << std::endl;
	}
}