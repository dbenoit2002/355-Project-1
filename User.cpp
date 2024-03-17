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

float User::withdraw(float amount) {
    balance -= amount;
    return balance;
}

float User::deposit(float amount) {
    balance += amount;
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