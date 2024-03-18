#include <iostream>
/**
 * @brief simple function that calls for user input and allocates a strings worth of space
 * beforehand
 * 
 */
void function()
{
    std::cout<< "Gimme input: \n";
    std::string userInput;
    std::cin >> userInput;
}
int main()
{
    function();
}