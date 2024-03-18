#include <iostream>

using namespace std;

unsigned int mask = -1;

unsigned int maskNumber(unsigned int num)
{
    return num^mask;
}

int main()
{
    maskNumber(10);
}