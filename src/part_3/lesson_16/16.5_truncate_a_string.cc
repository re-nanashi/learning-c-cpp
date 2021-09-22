#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    using std::cout;
    using std::endl;
    using std::string;

    string sampleStr{"Hello String! Wake up to a beautiful day!"};
    cout << "The original sample string is: " << endl;
    cout << sampleStr << endl << endl;

    // Delete characters give position and count
    cout << "Truncating the second sentence: " << endl;
    sampleStr.erase(13, 28);
    cout << sampleStr << endl << endl;

    // Find character 'S' using find() algorithm
    string::iterator iCharS = find(sampleStr.begin(), sampleStr.end(), 'S');

    // If character found, 'erase' to delete a character
    cout << "Erasing character 'S', from the sample string: " << endl;
    if (iCharS != sampleStr.end())
        sampleStr.erase(iCharS);

    cout << sampleStr << endl << endl;

    // Erase a range of characters using an overloaded version of erase()
    cout << "Erasing a range between begin() and end(): " << endl;

    // Verify the length after the erase() operation above
    if (sampleStr.length() == 0)
        cout << "The string is empty" << endl;

    return 0;
}
