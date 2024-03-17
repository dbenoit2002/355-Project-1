#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <math.h>
#include <string>
#include <type_traits>

#include "Bank.h"


/**
 * @brief Macro that calculates compound interest and stores it in fa
 * 
 * (p = principle, t = time (years), n = times calculated per year), r = interest rate
 */
#define compoundInterest(fa, p, t, n, r) \
    /*PRE10*/ \
    do { \
        fa = p * pow((1 + (r / (n * 100))), (n*t)); \
    } while(0) //PRE11

/**
 * @brief Thread function, calculates half of the interest
 * 
 * @param interest 
 * @param principle 
 * @param time 
 * @param rate 
 * @param mutex 
 */
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

/**
 * @brief Calculates simple interest using multithreading
 * 
 * @param principle 
 * @param time 
 * @param rate 
 * @return float 
 */
float conSimpleInterest(int principle, int time, float rate) {
    std::mutex mutex; //CON06
    float interest = 0;

    std::thread thread1(interestHelper, &interest, principle, time, rate, &mutex);
    std::thread thread2(interestHelper, &interest, principle, time, rate, &mutex);
    thread1.join();
    thread2.join(); 

    return interest; //ERR59
}

template <typename Arg, typename... Ts, typename std::enable_if<std::is_integral<Arg>::value>::type * = nullptr>

/**
 * @brief Variadic function, calculates simple and compound interest based on given pairs of principle and rate,
 * 
 * (t = 10, n = 4)
 * 
 * @param i 
 * @param all 
 * @return true 
 * @return false 
 */
bool calculateInterest(Arg i, Ts... all) { //DCL50, MSC52
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
