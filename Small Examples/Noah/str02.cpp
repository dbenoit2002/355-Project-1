#include <iostream>

int main()
{
    int n = 0;
    int done = 0;
    std::cout << "Please enter a number from 1 to 10: \n" << std::flush;
    std::cin >> n;
    while(done != 1)
    {
        if(std::cin.fail())
        {
            std::cout << "That isn't a number. Try again." << std::endl;
            std::cin.clear();
        }
        if(n<1 || n>10)
        {
            std::cout << "That is out of range." << std::endl;
        }
        std::cout << "You have entered a usable number." << std::endl;
        done = 1;
    }
}