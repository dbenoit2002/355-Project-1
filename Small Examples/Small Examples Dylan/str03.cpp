#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string source = "This is a long string";
    string destination = source;

    cout<<"Destination: "<<destination<<endl;

    char source2[] = "This is another long string";
    char destination2[sizeof(source2)];

    strncpy(destination2, source2, sizeof(destination2) - 1);
    destination2[sizeof(destination2) - 1] = '\0'; // Ensure null termination

    cout<<"Destination 2: "<<destination2<<endl;

    return 0;
}