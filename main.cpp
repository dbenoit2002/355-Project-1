#include <iostream>
#include <array>
#include <vector>
#include "Bank.cpp"
#include "User.cpp"

using namespace std;

User* createUsers() {       
    std::aligned_storage<sizeof(User[10]), alignof(User[10])>::type buffer; //MEM54
    User* arrptr = ::new (&buffer) User[10];
    if(!arrptr) { //MEM52
        std::cout << "Could not create userArr";
        return nullptr;
    }
    return arrptr;
}

User* createUsersHelper() { //ERR58
    try {
        return createUsers();
    } catch (...) {
        std::cout << "An exception occured";
        return nullptr;
    }
}

User* userArr = createUsersHelper();

int main() {
    int principle = 10000;
    int time = 7;
    float rate = 6.25;

    float result = conSimpleInterest(principle, time, rate);
    std::cout << result << "\n";
  
    int n = 4;

    compoundInterest(result, principle, time, n, rate);
    std::cout << result << "\n";

    User user1("User 1", 1);
    std::cout << user1.deposit(1000) << "\n";
    std::cout << user1.withdraw(100) << "\n";

    User user2("User 2", 2);
    User user3("User 3", 3);

    user1.takeLoan(1000, 5.0);
    user2.takeLoan(10000, 6.25);
    user3.takeLoan(100000, 10.0);

    calculateInterest(user1.getPrinciple(), user1.getRate(),
                      user2.getPrinciple(), user2.getRate(),
                      user3.getPrinciple(), user3.getRate());
  
    vector<int> bankAccounts = {0, 1, 2, 3, 4};
    vector<int>::iterator it = bankAccounts.begin();
    
    while(it != bankAccounts.end())
    {
        if(it >= bankAccounts.begin() && it < bankAccounts.end())
        {
            cout << *it <<endl;
        }
        else
        {
            cerr<<"Index out of range"<<endl;
        }
        advance(it, 1);
        //do something with accounts
    }
}