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
}