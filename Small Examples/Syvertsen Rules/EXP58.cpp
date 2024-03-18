#include <cstdarg>
#include <iostream>

/**
 * @brief Multiply an indeterminate amount of numbers together
 * 
 * @param count An unknown quantity of arguments of type int
 * @return int product, the product of all arguments
 */
 int multiplyNumbers(int count...){
  int product = 1;
  std::va_list args;
  va_start(args, count);
  for(int i = 0; i < count; i ++){
    product *= va_arg(args, int);
  }
  va_end(args);
  return product;
 }

 int main(){
  std::cout << multiplyNumbers(4,8,10,20,50) << std::endl;
 }