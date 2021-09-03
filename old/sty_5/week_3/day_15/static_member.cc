#include <iostream>

class Cat {
public:
  Cat(int age) : its_age_(age) { how_many_cats++; }
  virtual ~Cat() { how_many_cats--; }
  virtual int GetAge() { return its_age_; }
  virtual void SetAge(int age) { its_age_ = age; }
  static int how_many_cats;

private:
  int its_age_;
};

int Cat::how_many_cats = 0;

int main() {
  const int MAX_CATS = 5;
  int i;
  Cat *CatHouse[MAX_CATS];

  for (i = 0; i < MAX_CATS; ++i)
    CatHouse[i] = new Cat(i);

  for (i = 0; i < MAX_CATS; ++i) {
    std::cout << "There are ";
    std::cout << Cat::how_many_cats;
    std::cout << " cats left! " << std::endl;
    std::cout << "Deleting the one that is ";
    std::cout << CatHouse[i]->GetAge();
    std::cout << " years old" << std::endl;
    delete CatHouse[i];
    CatHouse[i] = 0;
  }
  return 0;
}
