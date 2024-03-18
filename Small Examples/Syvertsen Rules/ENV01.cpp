#include <iostream>

/**
 * @brief Checks if the environmental variable 'PATH' is not null
 * 
 * @return true 
 * @return false 
 */
bool checkPath(){
  char * thePath = nullptr;
  thePath = getenv("PATH");
  if (thePath != NULL){
    return true;
  }
  else{
    return false;
  }
}

int main(){
  std::cout << checkPath() << std::endl;
}