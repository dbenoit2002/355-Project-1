//By Brian Nicolellis

#include <thread>
#include <mutex>
#include <iostream>

std::mutex mutex;
int count = 0;

/**
 * @brief Adds 1 to global variable count,
 * Unlocks mutex in case of an exception
 * 
 */
void add(int x, int y) {
    mutex.lock();
    try {
        count++;
    } catch (...) {
        mutex.unlock(); //manually unlock
        std::cout << "An exception occured";
        throw;
    }
    mutex.unlock();
}

int main() {
    std::thread thread1(add);
    std::thread thread2(add);
    thread1.join();
    thread2.join();
    std::cout << "count = " << count;
}