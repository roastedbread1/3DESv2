#pragma once
#include <string>


std::string convertDecimalToBinary(int decimal);
int convertBinaryToDecimal(std::string binary);
std::string shiftLeftOnce(std::string key_chunk);
std::string shiftLeftTwice(std::string key_chunk);
std::string xorStrings(std::string a, std::string b);
void generateKeys(std::string key);
