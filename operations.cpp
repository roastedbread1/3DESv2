#include<string>
#include <cmath>
#include <bitset>
//converts a decimal number to a binary string
std::string convertDecimalToBinary(int decimal) {
	std::string binary;
	while (decimal != 0) {
		binary = (decimal % 2 == 0 ? "0" : "1") + binary;
		decimal /= 2;
	}
	while (binary.length() < 4) {
		binary = "0" + binary;
	}
	return binary;
}
//converts a binary string to a decimal number
int convertBinaryToDecimal(std::string binary) {
	int decimal = 0;
	int counter = 0;
	int size = binary.length();
	for (int i = size - 1; i >= 0; i--) {
		if (binary[i] == '1') {
			decimal += pow(2, counter);
		}
		counter++;
	}
	return decimal;
}

//circular left shift by 1

std::string shiftLeftOnce(std::string key_chunk) {
	std::string shifted = "";
	for (int i = 1; i < 28; i++) {
		shifted += key_chunk[i];
	}
	shifted += key_chunk[0];
	return shifted;
}

//circular left shift by 2
std::string shiftLeftTwice(std::string key_chunk) {
	std::string shifted = "";
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 28; j++) {
			shifted += key_chunk[j];
		}
		shifted += key_chunk[0];
		key_chunk = shifted;
		shifted = "";
	}
	return key_chunk;
}
//xor strings
std::string xorStrings(std::string a, std::string b) {
	std::string result = "";
	int size = b.size();
	for (int i = 0; i < size; i++) {
		if (a[i] != b[i]) {
			result += "1";
		}
		else {
			result += "0";
		}
	}
	return result;
}

//ascii to binary
std::string asciiToBinary(const std::string& ascii) {
	std::string binary = "";
	for (char c : ascii) {
		std::bitset<8> bin(c);  
		binary += bin.to_string();  
	}
	return binary;
}
