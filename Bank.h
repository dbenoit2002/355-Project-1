#ifndef BANK_H_
#define BANK_H_

#include <iostream>
using namespace std;

class Bank
{
  double deposit;
  double interest;
  double timeInYears;

  public:
    Bank(double amt, double rate, double time);
    double simpleInterest();
};

#endif