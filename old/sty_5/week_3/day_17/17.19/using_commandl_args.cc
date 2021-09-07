#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Recieved " << argc << " arguments...\n";

  for (int i = 0; i < argc; ++i)
    std::cout << "argument " << i << ": " << argv[i] << std::endl;

  return 0;
}
