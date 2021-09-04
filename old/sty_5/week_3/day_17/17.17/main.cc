#include <fstream>
#include <iostream>

int main() {
  char fileName[80];
  char buffer[255];
  std::cout << "Please reenter the file name: ";
  std::cin >> fileName;

  std::ifstream fin(fileName);
  if (fin) {
    std::cout << "Current file contents:\n";
    char ch;
    while (fin.get(ch))
      std::cout << ch;
    std::cout << "\n***End of file contents.***\n";
  }
  fin.close();

  std::cout << "\nOpening " << fileName << " in append mode...\n";

  // std::ios::app = append at the end of file
  std::ofstream fout(fileName, std::ios::app);
  if (!fout) {
    std::cout << "Unable to open " << fileName << " for appending.\n";
    return (1);
  }

  std::cout << "\nEnter text for the file: ";
  std::cin.ignore(1, '\n');
  std::cin.getline(buffer, 255);
  fout << buffer << "\n";
  fout.close();

  fin.open(fileName);
  if (!fin) {
    std::cout << "Unable to open " << fileName << " for reading.\n";
    return (1);
  }
  std::cout << "\nHere's the contents of the file:\n";
  char ch;
  while (fin.get(ch))
    std::cout << ch;
  std::cout << "\n***End of file contents.***\n";
  fin.close();
  return 0;
}
