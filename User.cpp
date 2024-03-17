#include <string>

#include "User.h"
#include <iostream>

using namespace userNamespace;

User::User(void) {
    name = "";
    id = 0;
    balance = 0;
    principle = 0;
    rate = 0;
}

User::User(std::string name, int id) {
    this->name = name;
    this->id = id;
    balance = 0;
    principle = 0;
    rate=0;
}

//EXP50
void User::processTransactions(int depositAmount, int withdrawalAmount) {
    std::cout << "Starting transactions for " << name << ".\n";

    //Deposit deposit
    this->deposit(depositAmount);
    std::cout << "Deposited " << depositAmount << ".\n";

    //Withdrawal
    if (withdrawalAmount <= depositAmount) {
        this->withdraw(withdrawalAmount);
        std::cout << "Withdrew " << withdrawalAmount << ".\n";
    } else {
        std::cout << "Withdrawal amount exceeds the deposited amount, transaction not processed.\n";
    }
}

// float User::withdraw(float amount) {
//     balance -= amount;
//     return balance;
// }

//Updated the above code to ensure the numbers are right and won't go into negatives
//Feel free to go back to original and remove if too much
float User::withdraw(float amount) {
    if (amount > balance) {
        std::cout << "Withdrawal failed. Insufficient balance.\n";
        return balance; // Could use a specific value or throw an exception to indicate failure.
    }
    balance -= amount;
    std::cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << ".\n";
    return balance;
}


// float User::deposit(float amount) {
//     balance += amount;
//     return balance;
// }

//Same thing as withdraw, updated to ensure numbers are correctly checked
float User::deposit(float amount) {
    if (amount < 0) {
        std::cout << "Deposit failed. Negative amount.\n";
        return balance; // Could use a specific value or throw an exception to indicate failure.
    }
    balance += amount;
    std::cout << "Deposit of $" << amount << " successful. New balance: $" << balance << ".\n";
    return balance;
}

std::string User::getName(void) {
    return name;
}

int User::getID(void) {
    return id;
}

float User::getBalance(void) {
    return balance;
}

void User::takeLoan(int amount, float rate) {
    principle = amount;
    this->rate = rate;
}

long User::getPrinciple(void) {
    return principle;
}

long User::getRate() {
    return rate;
}

void comparison(User &user1, User &user2)
{
    if(user1 != user2)
    {
        std::cout<<"These differ.\n";
    }
}
