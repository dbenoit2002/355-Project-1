/**
 * @file ctr55.cpp
 * @author Dylan Benoit
 * @brief Safely advance the iterator without going out of range
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
    vector<int>::iterator it = myVector.begin();

    advance(it, 2); //advances the iterator by 2
    if(it != myVector.end())
    {
        cout<<"Element at index "<< 2 << " is: "<<*it<<endl;
    }
    else{
        cerr<<"Iterator out of range"<<endl;
    }

    return 0;
}