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

int main()
{
    int input{0};
    std::cout << "Please enter a number (1-100) for the computer to guess:  \n";
    std::cin >> input;

    if (input > 100 || input < 0)
    {
        std::cout << "Invalid input\n";
        return 0;
    }

    //generate a range 1 - 100
    int arr[100];
    for (int i = 0; i < 100; ++i)
    {
        arr[i] = i + 1;
    }

    std::string q_ans{" "};
    int counter{0};

    int low{0}, high{99};

    while (counter < 7)
    {
        int mid = (high + low) / 2;
        int guess = arr[mid];

        if (guess == input)
        {
            std::cout << "I get it now. The number you entered is " << guess << "\n";
            return 0;
        }

        std::cout << "Is your number greater than " << guess << " ? Y/N \n";
        std::cin >> q_ans;
        if (!checkIfLegal(q_ans))
        {
            std::cout << "Invalid inputl\n";
            continue;
        }

        if (q_ans == "Y")
        {
            std::cout << "Ok let me rethink my guess. \n";
            low = mid + 1;
            ++counter;
        }
        else
        {
            std::cout << "Hmmmmmm. lower than that huh. \n";
            high = mid - 1;
            ++counter;
        }
    }

    std::cout << "You lied didn't you. \n";

    return 0;
}
