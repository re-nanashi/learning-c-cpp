#include <iostream>

constexpr double GetPi() { return 22.0 / 7; }
constexpr double TwicePi() { return 2 * GetPi(); }

int main() {
  double radius{0.0};
  std::cout
      << "Enter radius to compute the Area and Circumference of a circle.\n";
  std::cin >> radius;

  double area = radius * radius * GetPi();
  double circumference = radius * TwicePi();

  std::cout << "Area: " << area << "\n";
  std::cout << "Circumference: " << circumference << "\n";

  return 0;
}
