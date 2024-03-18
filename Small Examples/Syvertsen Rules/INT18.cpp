#include <iostream>

/**
 * @brief Compares an int to a long and returns the larger number
 * 
 * @param i an integer
 * @param j a long
 * @return either an int or long, whichever is larger
 */
int compareNumbers(int i, long j){
  if((long)i < j){
    return j;
  }
  else{
    return i;
  }
}

int main(){
  std::cout << compareNumbers(5, 10) << std::endl;
  std::cout << compareNumbers (10, 1) << std::endl;
  std::cout << compareNumbers (1, 1) << std::endl;
  std::cout << compareNumbers (10, 2147000000) << std::endl;
}