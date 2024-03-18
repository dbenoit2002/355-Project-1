#include <mutex>
#include <thread>
#include <iostream>

const int numThreads = 2;
  /**
   * @brief Prints "Hello!" a number of times equal to the thread number
   * 
   * @param i the thread number
   * @param theMutex a pointer to the mutex object
   */
  void printOut(int i,std::mutex *theMutex){
    std::lock_guard<std::mutex> lk(*theMutex);
    for(int k = 0; k < i; k++){
      std::cout << "Hello!" << std::endl;
    }
    
  }

  /**
   * @brief Uses multithreading to print "Hello!" a number of times
   * 
   */
  void useThreads(int numThreads){
    std::thread threads[numThreads];
    std::mutex mtx;

    for (int i = 0; i < numThreads; i++){
      threads[i] = std::thread(printOut, i,&mtx);
    }

    for(int i = 0; i < numThreads; i++){
      threads[i].join();
    }
  }

int main(){
  useThreads(5);
}