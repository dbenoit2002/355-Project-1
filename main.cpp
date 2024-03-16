#include "Bank.h"
#include "Bank.cpp"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int numOfBanks;
    cout<<"How many banks would you like? (Has to be an integer number): ";
    cin>>numOfBanks;
    
    vector<Bank*> banks(numOfBanks, nullptr);
    for(int i = 0; i < banks.size(); i++)
    {
        double amt = rand() % 200000 + 10;
        double rate = rand() % 10 + 1;
        double time = rand() % 15 + 1;

        banks[i] = new Bank(amt, rate, time);
    }

    for(int i = 0; i < banks.size(); i++)
    {
        cout<<"\nBank #"<<i+1<<"'s interest: $"<<banks[i]->simpleInterest()<<endl;
        delete banks[i];
    }

    return 0;
}