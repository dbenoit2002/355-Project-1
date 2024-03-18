#include <string>

class Car {
    class Engine *impl;
  public:
    ~Car();
  };

  class Engine{
    std::string make;
    int horsepower;
  };

  /**
   * @brief Destroy the Car:: Car object and delete incomplete pointer after
   * declaration of Engine class
   * 
   */
  Car::~Car() {
    delete impl;
  }

  int main() {
    Car car();
    Engine engine();
  }