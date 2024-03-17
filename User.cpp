#include <string>

#include "User.h"
#include <iostream>

using namespace userNamespace;

/**
 * @brief Construct a new User:: User object
 * 
 */
User::User(void) {
    name = "";
    id = 0;
    balance = 0;
    principle = 0;
    rate = 0;
}

/**
 * @brief Construct a new User:: User object
 * 
 * @param name 
 * @param id 
 */
User::User(std::string name, int id) {
    this->name = name;
    this->id = id;
    balance = 0;
    principle = 0;
    rate=0;
}

/**
 * @brief Withdraw amount from user's blance
 * 
 * @param amount 
 * @return float 
 */
float User::withdraw(float amount) {
    balance -= amount;
    return balance;
}

/**
 * @brief Add amount to user's balance
 * 
 * @param amount 
 * @return float 
 */
float User::deposit(float amount) {
    balance += amount;
    return balance;
}

/**
 * @brief Get the user's name
 * 
 * @return std::string 
 */
std::string User::getName(void) {
    return name;
}

/**
 * @brief Get the user's ID
 * 
 * @return int 
 */
int User::getID(void) {
    return id;
}

/**
 * @brief Get the user's balance
 * 
 * @return float 
 */
float User::getBalance(void) {
    return balance;
}

/**
 * @brief Takke a loan with given amount and rate
 * 
 * @param amount 
 * @param rate 
 */
void User::takeLoan(int amount, float rate) {
    principle = amount;
    this->rate = rate;
}

/**
 * @brief Get the user's principle amount
 * 
 * @return long 
 */
long User::getPrinciple(void) {
    return principle;
}

/**
 * @brief Get the users interest rate
 * 
 * @return long 
 */
long User::getRate() {
    return rate;
}

/**
 * @brief Compares user1 and user2 based on name
 * 
 * @param user1 
 * @param user2 
 */
void comparison(User &user1, User &user2)
{
    if(user1 != user2)
    {
        std::cout<<"These differ.\n";
    }
}