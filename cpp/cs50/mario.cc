#include <iostream>

int main()
{
    int user_input{0};
    do
    {
        std::cout << "Input a number (1-8): \n";
        std::cin >> user_input;
    } while (user_input < 1 || user_input > 8);

    for (int i = 1; i <= user_input; ++i)
    {
        // loop for the spaces
        for (int j = user_input - i; j != 0; --j)
        {
            std::cout << " ";
        }
        // loop for the left hash
        for (int k = 0; k < i; ++k)
        {
            std::cout << "#";
        }
        // 2 spaces in between
        std::cout << "  ";
        // loop for the right hash
        for (int l = 0; l < i; ++l)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }

    return 0;
}
