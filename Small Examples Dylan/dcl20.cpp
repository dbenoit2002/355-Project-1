#include <string>
#include <iostream>
using namespace std;

/*Sample function*/
void doSomething(void);

int main()
{
    doSomething();
    return 0;
}

void doSomething(void)
{
    string sample = "dcl20 example";
    cout<<sample<<endl;
}