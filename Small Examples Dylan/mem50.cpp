#include <iostream>
using namespace std;
int main()
{
    int* ptr = new int(39);

    cout<< "Value: "<<*ptr<<endl;

    // deallocate memory
    delete ptr;

    // set pointer to null
    ptr = nullptr;

    // cannot access memory after deallocation
    
    return 0;
}