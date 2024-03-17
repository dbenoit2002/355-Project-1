//By Brian Nicolellis

#include <iostream>

/**
 * @brief prints the size of an array
 * 
 * @param array 
 * @param size 
 */
void print_size(int array[], size_t size) {
    //std::cout << "size1 = " << sizeof(array) / sizeof(array[0]); 
    std::cout << "\nsize2 = " << size; 
}

int main() {
    int arr[20];
    print_size(arr, sizeof(arr)/sizeof(arr[0]));
}