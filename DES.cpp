#include "DES.h"
#include "permutation.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string encryption(string plaintext, vector<string> keys) {
    string output;
    string encrypted;
    for(int i = 0; i < 64; i++){
        output += plaintext[(int)IP[i] - 1];
    }

    for (int i = 0; i < 16; i++){
        string Left = output.substr(32,32);
        string Right_block = output.substr(32,32);
        Right_block = expansion(Right_block);
        Right_block = XOR(Right_block, keys[i], 48);
        Right_block = sBox(Right_block);
        Right_block = pBox(Right_block);
        string Right = XOR(Right_block, output.substr(0,32), 32);
        output = Left + Right;
    }
    output = output.substr(32,32) + output.substr(0,32);
    for(int i = 0; i < 64; i++){
        encrypted += output[(int)FP[i] - 1];
    }
    return encrypted;
    
}

string decryption(string encrypted, vector<string> keys) {
    string decrypted;
    string output;
    for(int i = 0; i < 64; i++){
        decrypted += encrypted[(int)IP[i] - 1];
    }
    decrypted = decrypted.substr(32,32) + decrypted.substr(0,32);
    for (int i = 0; i < 16; i++){
        string Right = decrypted.substr(0,32);
        string Left_block = decrypted.substr(0,32);
        Left_block = expansion(Left_block);
        Left_block = XOR(Left_block, keys[15 - i], 48);
        Left_block = sBox(Left_block);
        Left_block = pBox(Left_block);
        string Left = XOR(Left_block, decrypted.substr(32,32), 32);
        decrypted = Left + Right;
    }

    for(int i = 0; i < 64; i++){
        output += decrypted[(int)FP[i] - 1];
    }

    return output;
    
}
