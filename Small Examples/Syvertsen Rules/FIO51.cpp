#include <fstream>

/**
   * @brief Opens a file and writes "Hello!" to it
   * 
   */
  void writeHello(){
    std::ofstream file;
    file.open("HelloFile.txt");
    file << "Hello!";
    file.close();
  }

  int main (){
    writeHello();
  }