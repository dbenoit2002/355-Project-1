#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

int main()
{
    ifstream myFile;
    /*
        Open and close are used to guarentee the right file is being worked in
    */
   myFile.open("sample.txt");
   if(myFile.is_open())
   {
    string line;
    while(getline(myFile, line))
    {
        cout << line << endl;
    }
   }
   myFile.close();
}