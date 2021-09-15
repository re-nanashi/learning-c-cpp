// Write a program that tells the user the number of vowels in a sentece.
// My solution
// 1. Create a string with only vowels
// 2. Iterate through the user string
// 3. Check if current char(lowercased) could be found in vowel char array
// 4. If found increment the counter else do nothing

#include <algorithm>
#include <iostream>
#include <string>

bool isVowel(char c)
{
    char vowel[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    // vowel + length of char array as offset
    char *end = vowel + sizeof(vowel) / sizeof(vowel[0]);
    char *position = std::find(vowel, end, c);

    return (position != end);
}

int main()
{
    int number_of_vowels{0};
    std::string user_input{""};

    std::cout << "Enter a sentence: " << std::endl;
    std::getline(std::cin, user_input);

    for (int i = 0; i < user_input.length(); ++i)
    {
        char caseInsenstive = tolower(user_input[i]);
        if (isVowel(caseInsenstive))
        {
            ++number_of_vowels;
        }
    }

    std::cout << "User input contains " << number_of_vowels << " vowels." << std::endl;

    return 0;
}
