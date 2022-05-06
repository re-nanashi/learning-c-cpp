#include <fstream>
#include <iostream>

class Animal {
public:
  Animal(int weight, long days) : itsWeight(weight), DaysAlive(days) {}
  ~Animal() {}

  int GetWeight() const { return itsWeight; }
  void SetWeight(int weight) { itsWeight = weight; }

  long GetDaysAlive() const { return DaysAlive; }
  void SetDaysAlive(long days) { DaysAlive = days; }

private:
  int itsWeight;
  long DaysAlive;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return (1);
  }

  std::ofstream fout(argv[1], std::ios::binary);
  if (!fout) {
    std::cout << "Unable to open " << argv[1] << " for writing.\n";
  }

  Animal Bear(50, 100);
  fout.write((char *)&Bear, sizeof Bear);

  fout.close();

  std::ifstream fin(argv[1], std::ios::binary);
  if (!fin) {
    std::cout << "Unable to open " << argv[1] << " for reading.\n";
    return (1);
  }

  Animal BearTwo(1, 1);

  std::cout << "BearTwo weight: " << BearTwo.GetWeight() << std::endl;
  std::cout << "BearTwo days: " << BearTwo.GetDaysAlive() << std::endl;

  fin.read((char *)&BearTwo, sizeof BearTwo);

  std::cout << "BearTwo weight: " << BearTwo.GetWeight() << std::endl;
  std::cout << "BearTwo days: " << BearTwo.GetDaysAlive() << std::endl;
  fin.close();
  return 0;
}
