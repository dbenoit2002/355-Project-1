#include <iostream>

/**
 * @brief Allocates memory of size [size] to a string pointer
 * 
 * @param x a pointer to a string
 * @param size a size_t (non-negative integer) value
 * @return std::string* - A pointer to a string
 */
std::string* allocateStringSize(std::string* x, size_t size){
  if(size == 0){
    std::cout << "Invalid Length!" << std::endl;
    return x;
  }
  else{
    x = (std::string *)malloc(size);
    if(!x){
      std::cout << "Memory Allocation Failed!" << std::endl;
    }
    return x;
  }
}

int main(){
  std::string temp = "Hello World!";
  std::string * str;
  str = &temp;
  std::cout << allocateStringSize(str, 0) << std::endl;
  std::cout << allocateStringSize(str, 20) << std::endl;
  std::cout << allocateStringSize(str, 12) << std::endl;
}