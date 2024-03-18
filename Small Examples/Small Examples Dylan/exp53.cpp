/**
 * @file exp53.cpp
 * @author Dylan Benoit
 * @brief Reads the initialized variable over the unitialized
 * @version 0.1
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
using namespace std;
int main()
{
    int x;
    int y = 1;

    /* Incorrect use of the rule */
    // cout<<"Reading the unitialized variable: "<<x<<endl;
    cout<<"Read the intialized variable: "<<y<<endl;

    return 0;
}