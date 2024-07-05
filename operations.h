#pragma once
#include <string>
#include <vector>

std::string convertDecimalToBinary(int decimal);
int convertBinaryToDecimal(std::string binary);
std::string shiftLeftOnce(std::string key_chunk);
std::string shiftLeftTwice(std::string key_chunk);
std::string xorStrings(std::string a, std::string b);
std::vector<std::string> split(std::string s, int n);
std::string block(std::string s, int ind, int len);
std::vector<std::string> generateKeys(std::string key);
std::string asciiToBinary(const std::string& ascii);
std::string binaryToAscii(const std::string& binary);
void pad(std::string &s);
void repeat(std::string &s);
void input(std::string m, std::string &s);