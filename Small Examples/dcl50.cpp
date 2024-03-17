#include <type_traits>
#include <iostream>

/**
 * @brief searches for key in a variable amount of parameters
 * 
 * @tparam Arg 
 * @tparam Ts 
 * @tparam std::enable_if<std::is_integral<Arg>::value>::type 
 * @param key 
 * @param i 
 * @param all 
 * @return true 
 * @return false 
 */
template <typename Arg, typename... Ts, typename std::enable_if<std::is_integral<Arg>::value>::type * = nullptr>
bool searchList(int key, Arg i, Ts... all) { 
  int values[] = { i, all... };
  for (auto v : values) {
    if (key == v) {
      return true;
    } 
  }
  return false;
}

int main() {
  std::cout << searchList(3, 1,2,3,4,5);
  std::cout << "\n";
  std::cout << searchList(100, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20);
}