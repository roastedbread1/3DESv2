#include "operations.h"
#include "DES.h"
#include <string>
#include <vector>
#include <iostream>
#include "CBC.h"
#include "TDES.h"


void displayInFormats(const std::string& label, const std::string& data, bool isBinary = true) {
    std::cout << label << " (Length: " << data.length() << ")" << std::endl;
    if (isBinary) {
        std::cout << "Binary: " << data << std::endl;
        std::cout << "Hex   : " << binaryToHex(data) << std::endl;
        std::cout << "ASCII : " << binaryToAscii(data) << std::endl;
    }
    else {
        std::cout << "Binary: " << asciiToBinary(data) << std::endl;
        std::cout << "Hex   : " << binaryToHex(asciiToBinary(data)) << std::endl;
        std::cout << "ASCII : " << data << std::endl;
    }
    std::cout << std::endl;
}

void displayKeys(const std::string& asciiKey, const std::string& binaryKey) {
    std::cout << "Key (ASCII Length: " << asciiKey.length()
        << ", Binary Length: " << binaryKey.length() << ")" << std::endl;
    std::cout << "ASCII Key : " << asciiKey << std::endl;
    std::cout << "Binary Key: " << binaryKey << std::endl;
    std::cout << "K1: " << binaryKey.substr(0, 64) << std::endl;
    std::cout << "K2: " << binaryKey.substr(64, 64) << std::endl;
    std::cout << "K3: " << binaryKey.substr(128, 64) << std::endl;
    std::cout << std::endl;
}

int main() {

    std::string pt, key, key1, key2, key3;
    char choice;
    std::cout << "Choose input method:\n1. User input\n2. Use source file\n";
    std::cin >> choice;
    std::cin.ignore(); 

    switch (choice) {
    case '1': {
            input("Input your message : ", pt);
            input("Input your key : ", key);
            std::cout << std::endl;
        } break;

        case '2':
        {
            CypherSource source = ParseSource("cypher.source");
			pt = source.plaintext;
			key = source.key;
        } break;

        default: {
            std::cout << "Invalid choice. Exiting." << std::endl;
        } return 1;
    }


    std::string originalKey = key;
    repeat(key);
    std::string binaryKey = asciiToBinary(key);
    key1 = binaryKey.substr(0, 64);
    key2 = binaryKey.substr(64, 64);
    key3 = binaryKey.substr(128, 64);
    std::vector<std::string> rkeys1, rkeys2, rkeys3;
    rkeys1 = generateKeys(key1);
    rkeys2 = generateKeys(key2);
    rkeys3 = generateKeys(key3);

    pad(pt);
    std::string originalPt = pt;
    pt = asciiToBinary(pt);

    displayInFormats("IV", IV);
    displayInFormats("Plain text", asciiToBinary(originalPt));
    displayKeys(key, binaryKey);

    std::string ct = CBC("E", rkeys1, rkeys2, rkeys3, pt);
    displayInFormats("Cipher text", ct);

    std::string plaintext = CBC("D", rkeys1, rkeys2, rkeys3, ct);
    displayInFormats("Decrypted ciphertext", plaintext);

    return 0;
}