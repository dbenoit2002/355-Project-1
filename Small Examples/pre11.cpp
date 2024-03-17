#include <iostream>

/**
 * @brief Doubles num
 * 
 */
#define DOUBLE(num) ((num) *= 2)

int main() {
    int num = 10;
    int num2 = DOUBLE(num) + 10; //not ending w/ semicolon allows for additional statements after the macro
    std::cout << "Num: " << num << " , Num2: " << num2;
}