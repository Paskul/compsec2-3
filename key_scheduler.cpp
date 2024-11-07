#include "key_utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string shift_left(string sub_key){
    char first_char = sub_key[0];
    for(int i = 0; i < 27; i++){
        sub_key[i] = sub_key[i + 1];
    }
    sub_key[27] = first_char;
    return sub_key;
} 

vector<string> key_gen(string key){
    vector<string> sub_keys;
    string small_key="";
    for(int i =0; i<56; i++){
        small_key += key[(int)PC1[i] - 1];
    }

    string left = small_key.substr(0,28);
    string right = small_key.substr(28,28);
    for(int i =0; i<16; i++){
        if(i == 0||i==1||i==8||i==15){
            left = shift_left(left);
            right = shift_left(right);
        }else{
            left = shift_left(left);
            left = shift_left(left);
            right = shift_left(right);
            right = shift_left(right);
        }
        string final_sub_key = left + right;
        string round_key = "";
        for(int j = 0; j < 48; j++){
            round_key += final_sub_key[(int)PC2[j] - 1];
        }
        sub_keys.push_back(round_key);
    }
return sub_keys;
}
