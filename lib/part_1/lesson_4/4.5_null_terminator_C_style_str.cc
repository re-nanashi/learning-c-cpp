#include <iostream>

using std::cout;
using std::endl;

int main() {
  char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ',
                     'W', 'o', 'r', 'l', 'd', '\0'};
  cout << sayHello << endl;
  cout << "Size of array: " << sizeof(sayHello) << endl;

  cout << "Replacing space with null" << endl;
  sayHello[5] = '\0';
  cout << sayHello << endl;
  cout << "Size of array: " << sizeof(sayHello) << endl;

  return 0;
}
