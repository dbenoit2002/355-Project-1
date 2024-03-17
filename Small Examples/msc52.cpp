#include <iostream>

/**
 * @brief Determines if num is even
 * 
 * @param num 
 * @return int 
 */
int isEven(int num) {
    if(num % 2 == 0) {
        std::cout << "\nEven";
        return 0;
    } else {
        std::cout << "\nOdd";
        return 0;
    }
    return -1;
}

int main() {
    int result = isEven(10);
    result = isEven(9);
}
