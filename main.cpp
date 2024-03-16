#include <iostream>
#include "Bank.cpp"

int main() {
    int principle = 10000;
    int time = 7;
    float rate = 6.25;

    float result = conSimpleInterest(principle, time, rate);
    std::cout << result << "\n";

    int n = 4;

    compoundInterest(result, principle, time, n, rate);
    std::cout << result << "\n";

    User user1("John Doe", 1);
    std::cout << user1.deposit(1000) << "\n";
    std::cout << user1.withdraw(100) << "\n";
}