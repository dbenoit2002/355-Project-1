#include <iostream>
#include <vector>
#include <string>
using namespace std;

void accessStringElement(const string& str, size_t index)
{
    if(index < str.size())
    {
        char element = str[index];
        cout << "Element at index " << index << ": " << element << endl;
    }
    else
    {
        cerr<<"Error: Index out of range"<<endl;
    }
}

int main()
{
    string myString = "Hello, world!";

    // works correctly
    accessStringElement(myString, 0);
    accessStringElement(myString, 6);

    // index out of range
    accessStringElement(myString, 42);

    return 0;
}