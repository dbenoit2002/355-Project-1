#include <iostream>
#include <string>
using namespace std;

int main(){
    string myString = "Hello world!";

    const char& first_char = myString.front();
    cout<<"First character: "<< first_char << endl;

    
    char* last_char_ptr = &myString.back();
    *last_char_ptr = '#';
    cout<<"Modified string: "<< myString << endl;

    for(auto it = myString.begin(); it != myString.end(); ++it)
    {
        cout<<*it<<" ";
    }

    cout<<endl;
}