#include <algorithm>
#include <iostream>
#include <string>

size_t punctuation_counter(std::string input)
{
    decltype(input.size()) punct_cnt = 0;

    // count the number of punctuation char in input then increment
    for (auto c : input)
        if (ispunct(c))
            ++punct_cnt;

    return punct_cnt;
}

std::string upper_case(std::string s)
{
    std::string temp(s);
    // convert every char in temp to uppercase thru ref
    for (auto &cchar : temp)
        cchar = toupper(cchar);

    return temp;
}

void capitalize_first_letter(std::string &s)
{
    if (!s.empty())
    {
        for (std::string::iterator st = s.begin(); st != s.cend(); ++st)
        {
            if (st == s.begin())
                *st = toupper(*st);
            else
                *st = tolower(*st);
        }
    }
}

void capitalize_first_word(std::string &s)
{
    if (!s.empty())
    {
        for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
            s[index] = toupper(s[index]);
    }
}

int main()
{
    std::string s("hello WORLD!!!");

    std::cout << punctuation_counter(s) << " punctuation characters in " << s << std::endl;
    capitalize_first_letter(s);
    std::cout << "capitalize_first_letter: " << s << "\n";
    capitalize_first_word(s);
    std::cout << "capitalize_first_word: " << s << "\n";

    return 0;
}
