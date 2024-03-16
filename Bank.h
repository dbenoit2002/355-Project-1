#ifndef BANK_H
#define BANK_H

class User {
    private:
        std::string name;
        int id;
        float balance;

        long principle;
        long rate;

    public:
        User(std::string name, int id);
        float withdraw(float amount);
        float deposit(float amount);
        std::string getName();
        int getID();
        float getBalance();
        void takeLoan(int amount, float rate);
        long getPrinciple();
        long getRate();
};

void interestHelper(float *interest, int principle, int time, float rate, std::mutex *mutex);
float conSimpleInterest(int principle, int time, float rate);

#endif