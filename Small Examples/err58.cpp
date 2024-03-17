#include <exception>
#include <iostream>

/**
 * @brief exammple functions
 * 
 * @return int 
 */
int exampleFunc() {
    return 0;
}

/**
 * @brief helper function, handles exceptions before main executes
 * 
 * @return int 
 */
int helper_func() noexcept {
    try {
        return exampleFunc();
    } catch (...) {
        std::cout << "An exception occured";
        std::terminate();
    }
    // Unreachable.
}

int global_result = helper_func();
 
int main() {
    std::cout << global_result;
}