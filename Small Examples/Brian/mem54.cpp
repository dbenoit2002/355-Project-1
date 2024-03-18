//By Brian Nicolellis

#include <new>
#include <type_traits>
  
/**
 * @brief std::aligned_storage ensures the buffer has enough storage and suitable alignment
 * 
 */
void memoryFunction() {
    std::aligned_storage<sizeof(int[10]), alignof(int[10])>::type buffer;
    int *arrptr = ::new (&buffer) int[10];
}

int main() {
    memoryFunction();
}