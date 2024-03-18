/**
 * @file ctr50.cpp
 * @author Dylan Benoit
 * @brief Checks if the requested index is within the range of the container
 * @version 0.1
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> myVector = {1,2,3,4,5,6,7,8,9};

    int index = 2;
    if(index >= 0 && index < myVector.size())
    {
        cout<<"Element at index "<< index << " is: "<<myVector[index]<<endl;
    }
    else{
        cerr<<"Index out of range"<<endl;
    }

    return 0;
}