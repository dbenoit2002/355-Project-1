#include <iostream>

/**
   * @brief A Square Class
   * 
   */
  class Square {
    int numSides;

    public:
    /**
     * @brief Construct a new Square object
     * 
     */
      Square(){
        numSides = 4;
      }
    /**
     * @brief Construct a new Square object
     * 
     * @param sides an input number of sides
     */
      Square(int sides){
        numSides = sides;
      }
    /**
     * @brief Destroy the Square object
     * 
     */
      ~Square(){
        throw 1;
      }
  };

  /**
   * @brief A rectangle class
   * 
   */
  class Rectangle {
    int numSides;
    Square square;
  public:
  /**
   * @brief Construct a new Rectangle object
   * 
   * @param sides an input number of sides
   */
    Rectangle(int sides){
      numSides = sides;
      Square square = Square(4);
    }
    /**
     * @brief Destroy the Rectangle object
     * 
     */
    ~Rectangle()
    try {
      
    }
    catch (int num){
      if(num == 1){
        std::cout << num << std::endl;
      }
      return;
    }
  };

  int main (){
    Rectangle rectangle(4);
  }