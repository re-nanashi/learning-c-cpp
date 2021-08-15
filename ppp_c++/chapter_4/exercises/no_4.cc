#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

const std::vector<std::string> legal_answer{"Y", "N"};

bool checkIfLegal(std::string user_input)
{
    for (int i = 0; i < legal_answer.size(); ++i)
    {
        if (user_input == legal_answer[i])
        {
            return true;
        }
    }
    return false;
}

int numberGuesser()
{
    int arr[100];
    for (int i = 0; i < 100; ++i)
    {
        arr[i] = i + 1;
    }
    int low = 0, high = 99, mid = 49;
    int guess = arr[mid];
}

int main()
{
    int input{0}, counter;
    std::cout << "Please enter a number: (1-100)";
    std::cin >> input;

    if (input > 100 || input < 0)
    {
        std::cout << "Invalid input";
        return 0;
    }

    std::string q_ans{" "};
    bool f_quit = false;

    while (!f_quit)
    {

        std::cin >> q_ans;
        if (!checkIfLegal(q_ans))
        {
            std::cout << "input illegal\n";
            continue;
        }
    }
}
