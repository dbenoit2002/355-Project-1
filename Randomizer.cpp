#include <iostream>
#include <string>
#include <random>
using namespace std;

/*
    returns a random value between 0 and 100
    MSC50
*/
int randomizer()
{
    
    static std::random_device rd;
    int num = rand();
    mt19937 engine(num);
    uniform_int_distribution<int> dist(0,100);
    return dist(engine);
}