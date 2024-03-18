//By Brian Nicolellis

#include <thread>
#include <mutex>
#include <iostream>

std::mutex mutex; //mutex is created outside of threads, and outlives them
int count = 2;

/**
 * @brief multiplies global variable count by itself
 * 
 */
void sqr() {
    mutex.lock();
    count *= count;
    mutex.unlock();
}

int main() {
    std::thread thread1(sqr);
    std::thread thread2(sqr);
    thread1.join();
    thread2.join();
    std::cout << "count = " << count;
}