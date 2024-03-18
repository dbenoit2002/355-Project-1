//By Brian Nicolellis

#include <thread>
#include <mutex>
#include <iostream>

std::mutex mutex;
int count = 0;

/**
 * @brief Adds 1 to global variable count,
 * Uses mutex to avoid data race
 * 
 */
void add() {
    mutex.lock();
    count++;
    mutex.unlock();
}

int main() {
    std::thread thread1(add);
    std::thread thread2(add);
    thread1.join();
    thread2.join();
    std::cout << "count = " << count;
}