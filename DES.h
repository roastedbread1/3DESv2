#pragma once
#include <string>
extern std::string pt;
extern std::string round_keys[16];

std::string DES(std::string mode, std::vector<std::string> round_keys, std::string pt);
std::string TDES(std::string mode, std::vector<std::string> rkeys1,std::vector<std::string> rkeys2, std::vector<std::string> rkeys3, std::string pt);