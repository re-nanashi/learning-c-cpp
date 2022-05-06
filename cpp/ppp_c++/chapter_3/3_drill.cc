#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    std::cout << "Enter the name of the person you want to write to\n";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Dear " << first_name << "," << std::endl;
    std::cout << "\tHow are you? I am fine. I miss you." << std::endl;

    std::cout << "Enter the name of the other friend\n";
    std::string friend_name;
    std::cin >> friend_name;
    std::cout << "Have you seen " << friend_name << " lately?" << std::endl;
    ;

    char friend_sex{};
    std::cout << "Enter your friend's sex: f or m\n";
    std::cin >> friend_sex;

    if (friend_sex == 'm')
        std::cout << "If you see " << friend_name << ", please ask him to call me." << std::endl;
    ;
    if (friend_sex == 'f')
        std::cout << "If you see " << friend_name << ", please ask her to call me." << std::endl;
    ;

    std::cout << "Enter the age of the recipient\n";
    int age{};
    std::cin >> age;
    std::cout << "I hear you just had a birthday and you are " << age << " years old." << std::endl;

    if (age < 1 || age > 110)
        std::cout << "you're kidding!\n";
    if (age < 12)
        std::cout << "Next year you will be " << age + 1 << std::endl;
    if (age == 17)
        std::cout << "Next year you will be able to vote." << age + 1 << std::endl;
    if (age > 70)
        std::cout << "I hope you are enjoying retirement." << std::endl;

    std::cout << "Yours sincerely," << std::endl;
    std::cout << "_________\n"
              << "Fabro, John Reymar I.\n";
    return 0;
}