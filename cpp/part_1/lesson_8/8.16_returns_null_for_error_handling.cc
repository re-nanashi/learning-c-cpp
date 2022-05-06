// new(nothrow) = does not throw an exception, points pointer to null
#include <iostream>

int main() {
  int *pointsToManyNums = new (std::nothrow) int[0x1fffffff];

  // check if pointer is null
  if (pointsToManyNums) {
    delete[] pointsToManyNums;
  } else {
    std::cout << "Memory allocation failed. Ending program" << std::endl;
  }
  return 0;
}
