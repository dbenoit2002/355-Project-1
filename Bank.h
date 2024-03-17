#ifndef BANK_H
#define BANK_H

#include <mutex>

void interestHelper(float *interest, int principle, int time, float rate, std::mutex *mutex);
float conSimpleInterest(int principle, int time, float rate);
//INT 50
enum bankBranches {
    Houston,
    Boston,
    Normal,
    Chicago,
    Boise
};
//INT 50
bankBranches getBranch(int id);


#endif