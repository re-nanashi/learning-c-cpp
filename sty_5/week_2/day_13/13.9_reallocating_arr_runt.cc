// When you allocate an array on the heap, the array can be resized at runtime
#include <iostream>

int main() {
  int AllocationSize = 5;
  int *pArrayOfNumbers = new int[AllocationSize];
  int ElementsUsedSoFar = 0;
  int MaximumElementsAllowed = AllocationSize;
  int InputNumber = -1;

  std::cout << std::endl << "Next Number = ";
  std::cin >> InputNumber;

  while (InputNumber > 0) {
    pArrayOfNumbers[ElementsUsedSoFar++] = InputNumber;

    if (ElementsUsedSoFar == MaximumElementsAllowed) {
      int *pLargerArray = new int[MaximumElementsAllowed + AllocationSize];

      for (int CopyIndex = 0; CopyIndex < MaximumElementsAllowed; ++CopyIndex) {
        pLargerArray[CopyIndex] = pArrayOfNumbers[CopyIndex];
      }

      delete[] pArrayOfNumbers;
      pArrayOfNumbers = pLargerArray;
      MaximumElementsAllowed += AllocationSize;
    }

    std::cout << std::endl << "Next number = ";
    std::cin >> InputNumber;
  }

  for (int Index = 0; Index < ElementsUsedSoFar; Index++) {
    std::cout << pArrayOfNumbers[Index] << std::endl;
  }

  return 0;
}
