#ifndef BANK_H
#define BANK_H

#include <mutex>

void interestHelper(float *interest, int principle, int time, float rate, std::mutex *mutex);
float conSimpleInterest(int principle, int time, float rate);

#endif