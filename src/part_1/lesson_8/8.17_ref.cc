#include <iostream>

int main() {
  int original = 30;
  std::cout << "orignal = " << original << std::endl;
  std::cout << "original is at address: " << std::hex << &original << std::endl;

  int &ref1 = original;
  std::cout << "ref1 is at address: " << std::hex << &ref1 << std::endl;

  int &ref2 = ref1;
  std::cout << "ref2 is at address: " << std::hex << &ref2 << std::endl;
  std::cout << "Therefore, ref2 = " << std::dec << ref2 << std::endl;
  ref2 = 40;

  std::cout << "original = " << original << std::endl;
  std::cout << "ref1= " << ref1 << std::endl;
  return 0;
}
