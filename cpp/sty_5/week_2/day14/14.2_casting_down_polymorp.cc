#include <iostream>

enum TYPE { HORSE, PEGASUS };

class Horse {
public:
  virtual void Gallop() { std::cout << "Galloping ...\n"; }

private:
  int its_age;
};

class Pegasus : public Horse {
public:
  virtual void Fly() { std::cout << "I can fly! I can fly! I can fly!\n"; }
};

const int number_horses = 5;
int main() {
  Horse *Ranch[number_horses];
  Horse *p_horse;
  int choice, i;
  for (i = 0; i < number_horses; ++i) {
    std::cout << "(1) Horse (2) Pegasus: ";
    std::cin >> choice;
    if (choice == 2)
      p_horse = new Pegasus;
    else
      p_horse = new Horse;
    Ranch[i] = p_horse;
  }
  std::cout << std::endl;
  for (i = 0; i < number_horses; ++i) {
    Pegasus *p_peg = dynamic_cast<Pegasus *>(Ranch[i]);
    if (p_peg != NULL)
      p_peg->Fly();
    else
      std::cout << "Just a horse\n";
    delete Ranch[i];
  }
  return 0;
}
