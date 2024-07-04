#pragma once
#include <string>
#include <vector>
extern std::string IV;

std::string DES(std::string mode, std::vector<std::string> round_keys, std::string pt);
std::string TDES(std::string mode, std::vector<std::string> rkeys1,std::vector<std::string> rkeys2, std::vector<std::string> rkeys3, std::string pt);
std::string CBC(std::string mode, std::vector<std::string> rkeys1,std::vector<std::string> rkeys2, std::vector<std::string> rkeys3, std::string& in);