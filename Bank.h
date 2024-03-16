#ifndef BANK_H
#define BANK_H


void interestHelper(float *interest, int principle, int time, float rate, std::mutex *mutex);
float conSimpleInterest(int principle, int time, float rate);

class User {
    private:
        std::string name;
        int id;
        float balance;

    public:
        User(std::string name, int id);
        float withdraw(float amount);
        float deposit(float amount);
};

#endif