#include <string>
#include "DES.h"
#include "TDES.h"
#include "operations.h"
#include <vector>
#include <random>
#include <bitset>
#include <iostream>
// Generate a random IV as a vector of bytes
std::vector<uint8_t> generateRandomIV(size_t ivSize) {
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    std::uniform_int_distribution<unsigned int> dis(0, 255); // Use unsigned int instead
    std::vector<uint8_t> iv(ivSize);
    for (size_t i = 0; i < ivSize; ++i) {
        iv[i] = static_cast<uint8_t>(dis(gen)); // Cast the result to uint8_t
    }
    return iv;
}

// Convert the byte vector to a binary string
std::string bytesToBinaryString(const std::vector<uint8_t>& bytes) {
    std::string binaryString;
    for (uint8_t byte : bytes) {
        // Convert each byte to an 8-bit binary string and append to the result
        binaryString += std::bitset<8>(byte).to_string();
    }
    return binaryString;
}

size_t ivSize = 8;
std::vector<uint8_t> iv = generateRandomIV(ivSize);
std::string IV = bytesToBinaryString(iv);
// std::cout << "Generated IV: " << IV << std::endl;


std::string CBC(std::string mode, std::vector<std::string> rkeys1,std::vector<std::string> rkeys2, std::vector<std::string> rkeys3, std::string& in) {
    // std::vector<std::string> ins = split(in, 64);
    // std::vector<std::>
    std::string out = "";
    if (mode=="E") {
        std::string intermediate, out1;
        int ind = 0;
        while(ind<in.length()) {
            if (ind==0) {
                intermediate = xorStrings(IV, block(in, ind, 64));
            } else {
                intermediate = xorStrings(out1, block(in, ind, 64));
            }
            out1 = TDES(mode, rkeys1, rkeys2, rkeys3, intermediate);
            out+=out1;
            ind+=64;
        }
    } else if(mode =="D") {
        std::string in1, out1;
        int ind = 0;
        while(ind<in.length()) {
            in1 = block(in, ind, 64);
            if (ind==0) {
                out1 = xorStrings(IV, TDES(mode, rkeys1, rkeys2, rkeys3, in1));
            } else {
                out1 = xorStrings(block(in, ind-64, 64), TDES(mode, rkeys1, rkeys2, rkeys3, in1));
            }
            out+=out1;
            ind+=64;
        }
    }
    return out;
}