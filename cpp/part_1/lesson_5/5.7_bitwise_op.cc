#include <bitset>
#include <iostream>

int main() {
  std::cout << "Enter a number (0 - 255): ";
  unsigned short inputNum = 0;
  std::cin >> inputNum;

  std::bitset<8> inputBits(inputNum);
  std::cout << inputNum << "in binary is " << inputBits << std::endl;

  std::bitset<8> bitwiseNOT = (~inputNum);
  std::cout << "Logical NOT ~" << std::endl;
  std::cout << "~" << inputBits << " = " << bitwiseNOT << std::endl;

  std::cout << "Logical AND, & with 00001111" << std::endl;
  std::bitset<8> bitwiseAND = (0x0F & inputNum); // 0x0F is hex of 00001111
  std::cout << "00001111 & " << inputBits << " = " << bitwiseAND << std::endl;

  std::cout << "Logical OR, | with 00001111" << std::endl;
  std::bitset<8> bitwiseOR = (0x0F | inputNum);
  std::cout << "00001111 | " << inputBits << " = " << bitwiseOR << std::endl;

  std::cout << "Logical XOR, ^ with 00001111" << std::endl;
  std::bitset<8> bitwiseXOR = (0x0f ^ inputNum);
  std::cout << "00001111 ^ " << inputBits << " = " << bitwiseXOR << std::endl;

  return 0;
}
