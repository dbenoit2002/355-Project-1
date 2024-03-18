#include <iostream>

/**
   * @brief An enumerated list of accepted months
   * 
   */
  enum acceptableMonths {
    March = 3,
    April = 4,
    May = 5
  };

  /**
   * @brief A function to check if the input month is accepted
   * 
   * @param month an input month in the form of an int 1-12 to be checked for acceptability
   */
  void checkMonths (int month){
    if(month < March || month > May){
      std::cout << "Not an accepted month!" << std::endl;
    }
    else{
      acceptableMonths acceptedMonth = static_cast<acceptableMonths>(month);
      std::cout << acceptedMonth << std::endl;
    }
  }

  int main(){
    checkMonths(5);
    checkMonths(7);
  }