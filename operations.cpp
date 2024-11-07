#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string hexToBinary(string hexstring) {
  string binary_string;
  for (int i = 0; i < hexstring.size(); i++) {
    switch (hexstring[i]) {
    case '0':
      binary_string += "0000";
      break;
    case '1':
      binary_string += "0001";
      break;
    case '2':
      binary_string += "0010";
      break;
    case '3':
      binary_string += "0011";
      break;
    case '4':
      binary_string += "0100";
      break;
    case '5':
      binary_string += "0101";
      break;
    case '6':
      binary_string += "0110";
      break;
    case '7':
      binary_string += "0111";
      break;
    case '8':
      binary_string += "1000";
      break;
    case '9':
      binary_string += "1001";
      break;
    case 'A':
      binary_string += "1010";
      break;
    case 'a':
      binary_string += "1010";
      break;
    case 'B':
      binary_string += "1011";
      break;
    case 'b':
      binary_string += "1011";
      break;
    case 'C':
      binary_string += "1100";
      break;
    case 'c':
      binary_string += "1100";
      break;
    case 'D':
      binary_string += "1101";
      break;
    case 'd':
      binary_string += "1101";
      break;
    case 'E':
      binary_string += "1110";
      break;
    case 'e':
      binary_string += "1110";
      break;
    case 'F':
      binary_string += "1111";
      break;
    case 'f':
      binary_string += "1111";
      break;
    }
  }
  return binary_string;
}

vector<string> asciiToBinary(vector<string> blocks) {
  vector<string> binary_blocks;
  for (int i = 0; i < blocks.size(); i++) {
    string binary_block;
    for (int j = 0; j < 8; j++) {
      binary_block += bitset<8>(blocks[i][j]).to_string();
    }
    binary_blocks.push_back(binary_block);
  }
  return binary_blocks;
}

string binaryToAscii(string blocks) {
  string ascii_blocks = "";
  string ascii_blocks_trial = "";
  int extra_block = blocks.size() % 64;
  for (int i = 0; i < blocks.size() / 64; i++) {
    for (int j = 0; j < 8; j++) {
      unsigned long dec =
          bitset<8>(blocks.substr(64 * i, 64).substr(8 * j, 8)).to_ulong();
      ascii_blocks += dec;
    }
  }
  if (extra_block / 8) {
    for (int j = 0; j < extra_block / 8; j++) {
      unsigned long dec =
          bitset<8>(blocks.substr(blocks.size() - extra_block, extra_block)
                        .substr(8 * j, 8))
              .to_ulong();
      ascii_blocks_trial +=
          blocks.substr(blocks.size() - extra_block, extra_block)
              .substr(8 * j, 8);
      ascii_blocks += dec;
    }
  }
  return ascii_blocks;
}

int binToDec(string bin) {
  unsigned long dec = bitset<64>(bin).to_ulong();
  return dec;
}

string decToBin(int dec) {
  string binary = bitset<4>(dec).to_string();
  return binary;
}

string readfile(string filename) {
  ifstream t(filename);
  std::stringstream buffer;
  buffer << t.rdbuf();
  string output = buffer.str();
  return output;
}

string XOR(string bin1, string bin2, int len) {
  string output;
  if (len == 48) {
    bitset<48> binary1(bin1);
    bitset<48> binary2(bin2);
    output = (binary1 ^= binary2).to_string();
  } else if (len == 32) {
    bitset<32> binary1(bin1);
    bitset<32> binary2(bin2);
    output = (binary1 ^= binary2).to_string();
  } else {
    bitset<64> binary1(bin1);
    bitset<64> binary2(bin2);
    output = (binary1 ^= binary2).to_string();
  }
  return output;
}

vector<string> block_generation(string text, int encryption) {
  vector<string> blocks;
  if (encryption) {
    int num_of_blocks = text.size() / 8;
    int padding = (text.size()) % 8;
    if (padding) {
      int padding_num = 8 - padding;
      for (int i = 0; i < padding_num; i++) {
        if (i < 2) {
          text += 10;
        } else {
          text += (padding_num - 2);
        }
      }
      num_of_blocks += 1;
    } else {
      for (int i = 0; i < 8; i++) {
        if (i < 2) {
          text += 10;
        } else {
          text += 6;
        }
      }
      num_of_blocks += 1;
    }
    for (int i = 0; i < num_of_blocks; i++) {
      blocks.push_back(text.substr(i * 8, 8));
    }
    return blocks;
  } else {
    for (int i = 0; i < text.size() / 8; i++) {
      blocks.push_back(text.substr(i * 8, 8));
    }
    return blocks;
  }
}

int write_file(string text, string filename) {
  fstream file;
  file.open(filename, ios_base::out);
  if (!file.is_open()) {
    cout << "Unable to open the file.\n";
    return 0;
  }
  string myStr = text;
  file << myStr;
  file.close();
  return 0;
}

string unpadded(string padded) {
  string check = padded.substr((padded.size() - 4), 4);
  if (check.compare("1010") == 0) {
    if (padded.substr((padded.size() - 8), 4).compare("1010")) {
      return padded.substr(0, (padded.size() - 16));
    } else {
      return padded.substr(0, (padded.size() - 8));
    }
  } else {
    unsigned long num_bytes = bitset<4>(check).to_ulong();
    return padded.substr(0, (padded.size() - (8 * (num_bytes + 2))));
  }
}
