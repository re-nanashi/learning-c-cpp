#include <iostream>
#include <string>

void indentifyCard(std::string user_input);
std::string reverse(std::string);

int main()
{
    std::cout << "Plese enter credit card number: \n";

    std::string user_input{""};
    std::cin >> user_input;
    std::string reverse_input = reverse(user_input);
    std::size_t len = reverse_input.length();

    if (!(len > 12 && len < 17) || len == 14)
    {
        std::cout << "INVALID\n";
        return (1);
    }

    int sum_even = 0, sum_odd = 0;
    std::string concatenated_str = "";

    for (int i = 0; i < len; ++i)
    {
        if ((i + 1) % 2 == 0)
        {
            int doubled = (reverse_input[i] - '0') * 2;
            concatenated_str += std::to_string(doubled);
        }
        else
            sum_odd += reverse_input[i] - '0';
    }

    for (int i = 0; i < concatenated_str.length(); ++i)
    {
        sum_even += concatenated_str[i] - '0';
    }

    int total_sum = sum_even + sum_odd;
    if (total_sum % 10 == 0)
        indentifyCard(user_input);
    else
        std::cout << "INVALID\n";

    return 0;
}

std::string reverse(std::string str)
{
    std::string temp;
    for (int i = (str.length() - 1); i >= 0; --i)
        temp.push_back(str[i]);
    return temp;
}

void indentifyCard(std::string user_input)
{
    int first_two = std::stoi(user_input.substr(0, 2));
    int len = user_input.length();

    if (first_two > 50 && first_two < 56 && len == 16)
    {
        std::cout << "MASTERCARD\n";
    }
    else if ((first_two == 34 || first_two == 37) && len == 15)
    {
        std::cout << "AMERICAN EXPRESS\n";
    }
    else if ((len == 13 || len == 16) && user_input[0] == '4')
    {
        std::cout << "VISA\n";
    }
    else
    {
        std::cout << "INVALID\n";
    }
}
