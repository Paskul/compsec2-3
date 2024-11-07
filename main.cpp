#include "DES.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  // do not write code in this file. Only write code in the CBC.cpp
  string encryption_flag;
  cout << "Enter e or d to encrypt or decrypt: ";
  cin >> encryption_flag;
  string key = hexToBinary("02FFA374EB55F57B");
  string IV = hexToBinary("0C36AA5FB0C4A18D");
  if (encryption_flag[0] == 'e') {
    string input = "Computer Security is fun, but the course gets more challenging toward the end";
    vector<string> plaintext_blocks = block_generation(input, 1);
    vector<string> plaintext_binary = asciiToBinary(plaintext_blocks);
    string encrypted = CBC_encryption(plaintext_binary, key, IV);
    int dec = binToDec(encrypted);
    cout << dec << endl;
  } else if (encryption_flag[0] == 'd') {
    string input = "Computer Security is fun, but the course gets more challenging toward the end";
    vector<string> plaintext_blocks = block_generation(input, 1);
    vector<string> plaintext_binary = asciiToBinary(plaintext_blocks);
    string encrypted = CBC_encryption(plaintext_binary, key, IV);
    string encrypted_ascii = binaryToAscii(encrypted);
    vector<string> encrypted_blocks = block_generation(encrypted_ascii , 0);
    vector<string> encrypted_binary = asciiToBinary(encrypted_blocks);
    string decrypted_binary = CBC_decryption(encrypted_binary, key, IV);
    string decrypted_unpadded = unpadded(decrypted_binary);
    string decrypted = binaryToAscii(decrypted_unpadded);
    cout << decrypted;
  }
}
