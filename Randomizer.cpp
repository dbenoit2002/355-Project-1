#include <iostream>
#include <string>
#include <random>
using namespace std;

/*
    returns a random value between 0 and 100
    MSC50
*/
// int randomizer()
// {
    
//     static std::random_device rd;
//     int num = rand();
//     mt19937 engine(num);
//     uniform_int_distribution<int> dist(0,100);
//     return dist(engine);
// }

/*  
    Ensure your random number generator is properly seeded
    MSC51
*/

int randomizer()
{
    static std::random_device rd;
    // seed the generator
    static std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(0,100);

    return dist(engine); //generate a random number
}
