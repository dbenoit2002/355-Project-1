#include "Bank.h"
#include <iostream>

using namespace std;

Bank::Bank(double amt, double rate, double time)
{
    deposit = amt;
    interest = rate;
    timeInYears = time;
}

double Bank::simpleInterest()
{
    return (deposit * interest * timeInYears) / 100;
}