#ifndef USER_H
#define USER_H

#include <string>

namespace userNamespace { //DCL58
    class User {
        private:
            std::string name;
            int id;
            int branch_id;
            float balance;

            long principle;
            long rate;

        public:
            User();
            User(std::string name, int id);
            ~User();
            float withdraw(float amount);
            float deposit(float amount);
            std::string getName();
            int getID();
            float getBalance();
            int getBranchID();
            void takeLoan(int amount, float rate);
            long getPrinciple();
            long getRate();
            //OOP57 & EXP62
            bool operator!=(const User &rhs) const
            {
                return rhs.name > name;
            }
    };
}
#endif