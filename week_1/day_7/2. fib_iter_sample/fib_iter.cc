#include <iostream>

using namespace std;
unsigned int fib(unsigned int position);

int main()
{

    unsigned int answer, position;

    cout << "Which position? ";
    cin >> position;
    cout << endl;

    answer = fib(position);

    cout << answer << " is the ";
    cout << position << "th Fibonacci number. " << endl;
    return 0;
}
//fib(3) = 2
//fib(4) = 3

unsigned int fib(unsigned int n)
{
    unsigned int minus_two = 1, minus_one = 1, answer = 2;

    if (n < 3)
        return 1;

    for (n -= 3; n != 0; --n)
    {
        cout << n << endl;
        minus_two = minus_one;
        minus_one = answer;
        answer = minus_one + minus_two;
    }

    return answer;
}
