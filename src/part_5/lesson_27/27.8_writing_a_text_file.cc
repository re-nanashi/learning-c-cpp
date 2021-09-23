/*
fstream myFile;
myFile.open("HelloFile.txt", ios_base::in|ios_base::out|ios_base::trunc);

if (myFile.is_open())
{
    // do reading or writing here

   myFile.close();
}
ALTERNATE:
// Open a file for writing only
ofstream myFile("HelloFile.txt", ios_base::out);

// Open a file for reading only
ifstream myFile("HelloFile.txt", ios_base::in);
*/

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream myFile;
    myFile.open("HelloFile.txt", ios_base::out);

    if (myFile.is_open())
    {
        cout << "File open successful" << endl;

        myFile << "My first text file!" << endl;
        myFile << "Hello file!";

        cout << "Finished writing to file, will close now" << endl;
        myFile.close();
    }

    return 0;
}
