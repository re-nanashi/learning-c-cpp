#include <iostream>

int DemoConsoleOutput();

int main() { return DemoConsoleOutput(); }

int DemoConsoleOutput() {
  using std::cout;
  using std::endl;

  cout << "Performing subtraction  5 - 3 = " << 5 - 3 << endl;
  cout << "Performing multiplication  5 * 3 = " << 5 * 3 << endl;

  return 0;
}
