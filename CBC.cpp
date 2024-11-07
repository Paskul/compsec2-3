#include "DES.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The blocks has been padded and is already a vector of binary string
// The key and IV are also binary strings

// works
string CBC_encryption(vector<string> blocks, string key, string IV) {
  string encrypted;
  vector<string> keys = key_gen(key);
  string prevCipher = IV;

  for (int i = 0; i < blocks.size(); i++) {
    string XORed = XOR(blocks[i], prevCipher, 64);
    string encryptedBlock = encryption(XORed, keys);

    encrypted += encryptedBlock;
    prevCipher = encryptedBlock;
  }

  return encrypted;
}

// works now
string CBC_decryption(vector<string> blocks, string key, string IV) {
  string decrypted;
  vector<string> keys = key_gen(key);
  string prevCipher = IV;

  for (int i = 0; i < blocks.size(); i++) {
    string decryptedBlock = decryption(blocks[i], keys);
    string plainBlock = XOR(decryptedBlock, prevCipher, 64);

    decrypted += plainBlock;
    prevCipher = blocks[i];
  }
  
  return decrypted;
}
