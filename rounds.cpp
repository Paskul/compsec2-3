#include "des_utils.h"
#include "DES.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string expansion(string right_block){
    string expanded = "";
    for(int i = 0; i < 48; i++){
        expanded += right_block[(int)E[i] - 1];
    }
    return expanded;
}

string pBox(string right_block){
    string permuted = "";
    for(int i = 0; i < 32; i++){
        permuted += right_block[(int)P[i] - 1];
    }
    return permuted;
}

string sBox(string right_block){
    string substituted = "";
    for(int i = 0; i < 8; i++){
        string sub_block = right_block.substr(6*i, 6);
        string new_sub = "";
        new_sub += sub_block[0];
        new_sub += sub_block[5];
        new_sub += sub_block.substr(1,4);
        int index = binToDec(new_sub);
        int substituted_dec = (int)SBOXMAP[i][index];
        string substituted_block = decToBin(substituted_dec);
        substituted += substituted_block;   
    }

    return substituted;
}

