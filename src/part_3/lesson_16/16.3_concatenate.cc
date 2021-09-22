#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    string sampleStr1{"Hello"};
    string sampleStr2{"String!"};

    // Concatenate
    sampleStr1 += sampleStr2;
    cout << sampleStr1 << endl << endl;

    string sampleStr3{" Fun is not needing to use pointers!"};
    sampleStr1.append(sampleStr3);
    cout << sampleStr1 << endl << endl;

    const char *constCStyleString = " You however still can!";
    sampleStr1.append(constCStyleString);
    cout << sampleStr1 << endl;

    return 0;
}
