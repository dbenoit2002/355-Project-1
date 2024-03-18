//By Brian Nicolellis

#include <iostream>

/**
 * @brief header.h, example file
 * 
 * @return int 
 */
int exFunction() noexcept(true); // Implemented by the library

//------------------------------------------------------------------------- execution boundary

/**
 * @brief file1.cpp, example function
 * Does not throw exception in case of an error
 * 
 * @param num 
 * @return int 
 */
int exFunction(int num) noexcept(true) {
    if(num > 0) {
        return 0;
    }

    return -1; //returns in case of an error, does not throw exception
}
  
//------------------------------------------------------------------------- execution boundary

//#include "header.h"
/**
 * @brief file2.cpp, handles errors
 * 
 * @param num 
 */
void handleErrors(int num) {
    if (exFunction(num) == -1) {
        std::cout << "\nError has occured";
    }
    else {
        std::cout << "\nNormal Execution";
    }
}

int main() {
    handleErrors(10);
    handleErrors(0);
}