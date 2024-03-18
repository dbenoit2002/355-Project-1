//Use conformant array parameters

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

void initializeArray(size_t n, std::vector<int>& arr, int value) 
{
    for (size_t i = 0; i < n; i++) {
        arr[i] = value;
    }
}

int main() 
{
    std::vector<int> myArray(5); // Vector with 5 elements
    initializeArray(5, myArray, -1); 

    for (int val : myArray) {
        std::cout << val << ' ';
    }
    std::cout << '\n';

    return 0;
}
