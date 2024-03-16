#include <iostream>
#include "Bank.cpp"

int main() {
    int principle = 10000;
    int time = 7;
    float rate = 6.25;

    float result = conSimpleInterest(principle, time, rate);
    std::cout << result << "\n";

    vector<int> bankAccounts = {0, 1, 2, 3, 4};
    vector<int>::iterator it = bankAccounts.begin();
    
    while(it != bankAccounts.end())
    {
        if(it >= bankAccounts.begin() && it < bankAccounts.end())
        {
            cout << *it <<endl;
        }
        else
        {
            cerr<<"Index out of range"<<endl;
        }
        advance(it, 1);
        //do something with accounts
    }
}