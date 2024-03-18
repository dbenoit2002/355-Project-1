#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myFile;
    /*
        Open and close are used to guarentee the right file is being worked in
    */
   myFile.open("sample.txt");
   myFile << "Hey!" << endl;
   myFile.close();
}