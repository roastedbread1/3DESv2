#include "operations.h"
#include "DES.h"
#include <string>
#include <iostream>

int main() {
	std::string key = "1010101010111011000010010001100000100111001101101100110011011101";
	std:: string pt = "1010101111001101111001101010101111001101000100110010010100110110";
	std::cout << "Plain text: " << pt << std::endl;
	generateKeys(key);
	std::string ct = DES("E", pt);
	std::cout << "Cipher text: " << ct << std::endl;

	if (ct == "1001111000100110100111110101101011111010010011011011101101110000") {
		std::cout << "Plain text encrypted successfully." << std::endl;
	}
	else {
		std::cout << "Plain text encryption failed." << std::endl;
		/*
		int i = 15;
		int j = 0;
		while (1 > j) {
			std::string temp = round_keys[i];
			round_keys[i] = round_keys[j];
			round_keys[j] = temp;
			i--;
			j++;

		}
		pt  = ct;
		std::string decrypted = DES();
		std::cout << "Decrypted text:" << decrypted << std::endl;

		if (decrypted == apt) {
			std::cout << "Plain text encrypted and decrypted successfully." << std::endl;
		}
		*/
	}

	std::string plaintext = DES("D", ct);
	std::cout << "Decrypted ciphertext: " << plaintext << std::endl; 
	if(plaintext==pt) {
		std::cout << "ciphertext decrypted successfully." << std::endl;
	}
}