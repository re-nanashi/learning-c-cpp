#include <fstream>
#include <iostream>

int main() {
  char fileName[80];
  char buffer[255];
  std::cout << "File name: ";
  std::cin >> fileName;

  std::ofstream fout(fileName);
  fout << "This line written directly to the file...\n";
  std::cout << "Enter text for the file: ";
  std::cin.ignore(1, '\n');
  std::cin.getline(buffer, 255);
  fout << buffer << "\n";
  fout.close();

  std::ifstream fin(fileName);
  std::cout << "Here's the contents of the file:\n";
  char ch;
  while (fin.get(ch))
    std::cout << ch;

  std::cout << "\n***End of file contents.***\n";

  fin.close();
  return 0;
}
