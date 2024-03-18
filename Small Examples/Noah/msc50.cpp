#include <iostream>
#include <random>
/**
 * @brief Prints out 10 random numbers seeded through the Mersenne twister algorithm
 * 
 */
void function()
{
    std::uniform_int_distribution<int> dist(0,100);
    static std::random_device rd;
    int num = rand();
    std::mt19937 engine(num);
    
    for(int i = 0; i < 10; i++)
    {
        std::cout<< dist(engine) << "\n";
    }
}

int main()
{
    function();
}