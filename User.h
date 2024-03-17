#ifndef USER_H
#define USER_H

#include <string>
#include <mutex>

namespace userNamespace { //DCL58
    class User {
        private:
            std::string name;
            int id;
            float balance;

            long principle;
            long rate;

            std::mutex balanceMutex; //thread safe

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

            void processTransactions(int depositAmount, int withdrawalAmount); //EXP50

            //OOP57 & EXP62
            bool operator!=(const User &rhs) const
            {
                return rhs.name > name;
            }
    };
}
#endif
