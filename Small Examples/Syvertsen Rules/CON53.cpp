#include <mutex>
#include <thread>

class Balloon{
    int size;
  public:
    void makeSize(int x) { size = x;}
    std::mutex mtx;
  };
  /**
   * @brief Set the size of Balloon Objects
   * 
   * @param i A reference to a balloon object
   * @param j A reference to a second balloon object
   */
  void setSize(Balloon *i, Balloon *j){
    std::mutex * first = &i->mtx;
    std::mutex * second = &j->mtx;

    //lock in manual order
    std::lock_guard<std::mutex> firstLock(*first);
    std::lock_guard<std::mutex> secondLock(*second);

    i->makeSize(10);
    j->makeSize(20);

  }
  /**
   * @brief Use multithreading to set balloon sizes
   * 
   * @param x A reference to a balloon object
   * @param y A second reference to a balloon object
   */
  void makeBalloons(Balloon *x, Balloon *y){
    std::thread thread1(setSize, x, y);
    std::thread thread2(setSize, y, x);
    thread1.join();
    thread2.join();
  }

  int main() {
    Balloon *x;
    Balloon *y;
    x = new Balloon();
    y = new Balloon();
    makeBalloons(x, y);
  }