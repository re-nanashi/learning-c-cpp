#include <iostream>

class SomeClass {
public:
  SomeClass();
  ~SomeClass();

private:
  int mem_var_;
  static int static_var;
};

SomeClass::SomeClass() : mem_var_(1) { static_var++; }

SomeClass::~SomeClass() { static_var--; }

int SomeClass::static_var = 0;

int main() { return 0; }
