#include <iostream>

/**
 * @brief takes a reference to an integer and modifies the integer directly.
 *  The integer must be able to be modified (not constant)
 * 
 * @param i a non-constant modifiable integer.
 */
int changeInt(int &i) {
i = 42;
return i;
} 
/**
* @brief Set the Int variable used in changeInt
* 
*/
int setInt() {
int i = 4;
i = changeInt(i);
return i;
}

int main(){
std::cout << setInt() << std::endl;
}