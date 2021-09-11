#include <iostream>

int fib(int num);

int main() {
  int number = 10;
  std::cout << fib(number);
  return 0;
}

int fib(int num) {
  if (num < 2)
    return num;

  return (fib(num - 1) + fib(num - 2));
}
