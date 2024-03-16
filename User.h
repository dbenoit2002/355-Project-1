#ifndef USER_H
#define USER_H

#include <string>

class User {
    private:
        std::string name;
        int id;
        float balance;

        long principle;
        long rate;

    public:
        User();
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

#endif