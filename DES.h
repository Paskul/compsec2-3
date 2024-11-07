#include <iostream>
#include <string>
#include <vector>

using namespace std;

string shift_left(string sub_key);
vector<string> key_gen(string key);
string CBC_encryption(vector<string> blocks, string key, string IV);
string CBC_decryption(vector<string> blocks, string key, string IV);
string expansion(string right_block);
string pBox(string right_block);
string sBox(string right_block);
string round(string right_block, string key);
int binToDec(string bin);
string decToBin(int dec);
string XOR(string bin1, string bin2, int len);
string encryption(string plaintext, vector<string> keys);
string decryption(string encrypted, vector<string> keys);
vector<string> block_generation(string text, int encryption);
vector<string> asciiToBinary(vector<string> blocks);
string binaryToAscii(string blocks);
string readfile(string filename);
int write_file(string text, string filename);
string hexToBinary(string hexstring);
string unpadded(string padded);