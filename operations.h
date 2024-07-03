#pragma once
#include <string>
#include <vector>

std::string convertDecimalToBinary(int decimal);
int convertBinaryToDecimal(std::string binary);
std::string shiftLeftOnce(std::string key_chunk);
std::string shiftLeftTwice(std::string key_chunk);
std::string xorStrings(std::string a, std::string b);
std::vector<std::string> generateKeys(std::string key);
std::string asciiToBinary(const std::string& ascii);
std::string binaryToAscii(const std::string& binary);