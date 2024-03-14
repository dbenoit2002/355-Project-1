#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

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

    return interest;
}