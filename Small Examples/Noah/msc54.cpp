#include <iostream>
#include <csignal>
/**
 * @brief Make a plain old function to handle signal errors
 * 
 */
extern "C" void signalHandler(int signalNum)
{
    std::cout << "The signal that interrupted: " << signalNum;
}
/*
    if all goes well, nothing will print.
*/
int main()
{
    signal(SIGABRT, signalHandler);
    return(0);
}