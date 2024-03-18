#include <string>
#include <iostream>
using namespace std;

int main()
{
    string example;

    // append characters to string
    example.push_back('H');
    example.push_back('e');
    example.push_back('l');
    example.push_back('l');
    example.push_back('o');

    // access certain characters safely
    cout<< "First character "<<example.front()<<endl;
    cout<< "Last character "<<example.back()<<endl;

    // modify characters safely
    if(!example.empty()){
        example[0] = 'h';
        example.at(4) = 'a';
    }

    cout<<"modified string "<<example<<endl;


    return 0;
}