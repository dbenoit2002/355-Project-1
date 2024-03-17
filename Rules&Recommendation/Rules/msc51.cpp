//Ensure your random number generator is properly seeded

#include <random>
#include <iostream>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100); //Defining the range values, can be changed for specific range.

    for(int i = 0; i < 10; ++i)
    {
        std::cout << distrib(gen) << std::endl;
    }

    return 0;
}