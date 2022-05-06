#include <iostream>

class Cat {
public:
  Cat() {
    itsAge = 1;
    itsWeight = 5;
  }
  ~Cat();
  int GetAge() const { return itsAge; }
  int GetWeight() const { return itsWeight; }
  void SetAge(int age) { itsAge = age; }

private:
  int itsAge;
  int itsWeight;
};

Cat::~Cat() { std::cout << "Destructor called!\n"; }

int main() {
  Cat *Family = new Cat[10];
  int i;

  for (i = 0; i < 10; i++) {
    Family[i].SetAge(2 * i + 1);
  }

  for (i = 0; i < 10; ++i) {
    std::cout << "Cat #" << i + 1 << ": ";
    std::cout << Family[i].GetAge() << std::endl;
  }

  delete[] Family;

  return 0;
}
