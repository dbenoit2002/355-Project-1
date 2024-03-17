//Do not depend on the order of evaluation for side effects

#include <iostream>

//Incremented i separately
void f(int i, const int *b)
{
    int j = i + 1;
    int a = i + b[j];
    
    std::cout << a << std::endl;
}

int main() 
{
    int i = 1;
    int b[] = {1, 3, 5, 7, 9};

    f(i, b);

    return 0;
}