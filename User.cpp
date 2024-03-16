#include <string>

#include "User.h"

using namespace userNamespace;

User::User() {
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

std::string User::getName() {
    return name;
}

int User::getID() {
    return id;
}

float User::getBalance() {
    return balance;
}

void User::takeLoan(int amount, float rate) {
    principle = amount;
    this->rate = rate;
}

long User::getPrinciple() {
    return principle;
}

long User::getRate() {
    return rate;
}
