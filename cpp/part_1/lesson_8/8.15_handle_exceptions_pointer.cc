#include <iostream>

int main() {
  try {
    int *pointsToManyNums = new int[0x1fffffff];
  } catch (std::bad_alloc) {
    std::cout << "Memory allocation failed. Ending program" << std::endl;
  }

  return 0;
}
