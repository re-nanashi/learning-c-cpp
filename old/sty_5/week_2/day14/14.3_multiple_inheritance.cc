#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Horse {
public:
  Horse() { cout << "Horse constructor..."; }
  virtual ~Horse() { cout << "Horse destructor..."; }
  virtual void Whinny() const { cout << "Whinny!..."; }

private:
  int its_age_;
};

class Bird {
public:
  Bird() { cout << "Bird constructor..."; }
  virtual ~Bird() { cout << "Bird destructor"; }
  virtual void Chirp() const { cout << "Chirp..."; }
  virtual void Fly() const { cout << "I can fly! I can fly! I can fly! "; }

private:
  int its_weight_;
};

class Pegasus : public Horse, public Bird {
public:
  void Chirp() const { Whinny(); }
  Pegasus() { cout << "Pegasus Constructor..."; }
  ~Pegasus() { cout << "Pegasus Constructor..."; }
};

const int magic_number = 2;
int main() {
  Horse *ranch[magic_number];
  Bird *Aviary[magic_number];
  Horse *p_horse;
  Bird *p_bird;
  int choice, i;
  for (i = 0; i < magic_number; ++i) {
    cout << "\n(1)Horse (2)Pegasus: ";
    cin >> choice;
    if (choice == 2)
      p_horse = new Pegasus;
    else
      p_horse = new Horse;
    ranch[i] = p_horse;
  }
  for (i = 0; i < magic_number; ++i) {
    cout << "\n(1)Bird (2)Pegasus: ";
    cin >> choice;
    if (choice == 2)
      p_bird = new Pegasus;
    else
      p_bird = new Bird;
    Aviary[i] = p_bird;
  }

  cout << endl;
  for (i = 0; i < magic_number; ++i) {
    cout << "\nRanch[" << i << "]: ";
    ranch[i]->Whinny();
    delete ranch[i];
  }

  for (i = 0; i < magic_number; ++i) {
    cout << "\nAviary[" << i << "]: ";
    Aviary[i]->Chirp();
    Aviary[i]->Fly();
    delete Aviary[i];
  }
  return 0;
}
