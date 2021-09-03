#include <iostream>

void Square(int &, int &);
void Cube(int &, int &);
void Swap(int &, int &);
void GetVals(int &, int &);
void PrintVals(void (*)(int &, int &), int &, int &);

int main() {
  int val_one = 1, val_two = 2;
  int choice;
  bool f_quit = false;

  void (*p_func)(int &, int &);

  while (f_quit == false) {
    std::cout << "(0)Quit (1)Change Values (2)Square (3)Cube (4) Swap:";
    std::cin >> choice;

    switch (choice) {
    case 1:
      p_func = GetVals;
      break;
    case 2:
      p_func = Square;
      break;
    case 3:
      p_func = Cube;
      break;
    case 4:
      p_func = Swap;
      break;
    default:
      f_quit = true;
      break;
    }

    if (f_quit == false)
      PrintVals(p_func, val_one, val_two);
  }

  return 0;
}

void PrintVals(void (*p_func)(int &, int &), int &x, int &y) {
  std::cout << "x: " << x << "y: " << y << std::endl;
  p_func(x, y);
  std::cout << "x: " << x << "y: " << y << std::endl;
}

void Square(int &r_x, int &r_y) {
  r_x *= r_x;
  r_y *= r_y;
}

void Cube(int &r_x, int &r_y) {
  int temp;

  temp = r_x;
  r_x *= r_x;
  r_x = r_x * temp;

  temp = r_x;
  r_y *= r_y;
  r_x = r_x * temp;
}

void Swap(int &r_x, int &r_y) {
  int temp;
  temp = r_x;
  r_x = r_y;
  r_y = temp;
}

void GetVals(int &r_value_one, int &r_value_two) {
  std::cout << "New value for val_one: ";
  std::cin >> r_value_one;
  std::cout << "New value for val_two: ";
  std::cin >> r_value_two;
}
