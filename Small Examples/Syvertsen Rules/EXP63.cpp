#include <iostream>


/**
   * @brief output passed string
   * 
   * @param str a string passed using the move function
   */
  void outputString(std::string str){
    std::cout << str << std::endl;
  }

  /**
   * @brief loops through a string [input] times and passes the result to outputString
   * 
   * @param input an input number from the user
   */
  void loopString(int input){
    for(int i = 0; i < input; i++){
      std::string tempString = std::to_string(i);
      outputString(std::move(tempString));
    }
  }

  int main(){
    loopString(5);
  }