//By Brian Nicolellis

#include <iostream>

/**
 * @brief does nothing to x
 * 
 */
#define DO_NOTHING(x) \
    do { \
        int tmp = (x); \
        (x) = (x+x); \
        (x) = (x-tmp); \
    } while (0)

int main() {
    int num = 10;
    if(num > 0) {
        DO_NOTHING(num); //do while loop keeps ensures macro is executed as intended
    } else {    
        num = num + num;
    }
    std::cout << "Num: " << num;
}