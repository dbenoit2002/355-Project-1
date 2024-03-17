#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <math.h>
#include <string>
#include <type_traits>

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

//EXP50
void processTransactions(int deposit, int withdrawal) {
    static std::mutex accountMutex;
    std::lock_guard<std::mutex> lock(accountMutex);

    std::cout << "Processing deposit of $" << deposit << "\n";
    std::cout << "Processing withdrawal of $" << withdrawal << "\n";
}

//DCL50, MSC52
template <typename Arg, typename... Ts, typename std::enable_if<std::is_integral<Arg>::value>::type * = nullptr>
bool calculateInterest(Arg i, Ts... all) { 
    long values[] = { i, all... };
    int size = sizeof(values) / sizeof(values[0]); //ARR01
    float result;

    for(int i = 0; i < size; i += 2) {
        if(i == size) {
            return false; //not even # args
        }
        else {
            result = conSimpleInterest(values[i], 10, values[i+1]);
            std::cout << "Simple interest: " << result << "\n";
            compoundInterest(result, values[i], 10, 4, values[i+1]);
            std::cout << "Compound interest: " << result << "\n";
        }
    }
    return true;
}
