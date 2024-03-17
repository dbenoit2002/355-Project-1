namespace myNamespace { //create and modify your own namespace, not a standard namespace like std
    int add(int num1, int num2) {
        return num1 - num2;
    }
}

#include <iostream>
using namespace myNamespace;

int main() {
    std::cout << myNamespace::add(2, 3);
}
    