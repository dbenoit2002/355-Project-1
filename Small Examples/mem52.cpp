//By Brian Nicolellis

#include <cstring>
#include <new>
#include <iostream>

/**
 * @brief handles any allocation errors without throwing
 * 
 */
void memoryFunction() noexcept {
    int *newInt = new (std::nothrow) int;
    if (!newInt) {
        std::cout << "Error occured";
        return;
    }
}

int main() {
    memoryFunction();
}