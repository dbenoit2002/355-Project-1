#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <math.h>
#include <string>

#include "Bank.h"

#define compoundInterest(fa, p, t, n, r) \
    /*PRE10*/ \
    do { \
        fa = p * pow((1 + (r / (n * 100))), (n*t)); \
    } while(0) //PRE11

void interestHelper(float *interest, int principle, int time, float rate, std::mutex *mutex) {
    (*mutex).lock(); //CON52
    try {
        *interest += ((principle/2) * time * rate) / 100;
    } catch(...) {
        (*mutex).unlock(); //CON51
        std::cout << "An exception occured";
        throw;
    }
    (*mutex).unlock();
}

float conSimpleInterest(int principle, int time, float rate) {
    std::mutex mutex; //CON06
    float interest = 0;

    std::thread thread1(interestHelper, &interest, principle, time, rate, &mutex);
    std::thread thread2(interestHelper, &interest, principle, time, rate, &mutex);
    thread1.join();
    thread2.join(); 

    return interest; //ERR59
}

User::User(std::string name, int id) {
    this->name = name;
    this->id = id;
    balance = 0;
}

float User::withdraw(float amount) {
    balance -= amount;
    return balance;
}

float User::deposit(float amount) {
    balance += amount;
    return balance;
}