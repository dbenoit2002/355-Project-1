#include <iostream>
#include <array>
#include <vector>
#include "Bank.cpp"
#include "User.cpp"
#include "Randomizer.cpp"

using namespace std;

/**
 * @brief Creates and returns a pointer to a list of User objects
 * 
 * @return User* 
 */
void createUsers(User* arrptr) {       
    std::aligned_storage<sizeof(User[10]), alignof(User[10])>::type buffer; //MEM54
    //OOP55
    arrptr = new (&buffer) User[10];
    if(!arrptr) { //MEM52
        std::cout << "Could not create userArr";
    }
}

/**
 * @brief Calls createUsers(), catches any exceptions
 * 
 * @return User* 
 */
bool createUsersHelper(User* arrptr) { //ERR58
    try {
        createUsers(arrptr);
        return true;
    } catch (...) {
        std::cout << "An exception occured";
        return false;
    }
}

User* userArr = nullptr;
bool value = createUsersHelper(userArr);

int main() {
    int principle = 10000;
    int time = 7;
    float rate = 6.25;

    float result = conSimpleInterest(principle, time, rate);
    std::cout << result << "\n";
  
    int n = 4;

    compoundInterest(result, principle, time, n, rate);
    std::cout << result << "\n";

    //STR50 and STR51
    std::cout << "Please input a username: \n";
    string username;
    std::cin >> username;

    if(username == "")
    {
        std:cout << "Null value found. Defaulting...\n";
        username = "User 1";
    }

    User user1(username, 1);
    std::cout << user1.deposit(1000) << "\n";
    std::cout << user1.withdraw(100) << "\n";

    User user2("User 2", 2);
    User user3("User 3", 3);

    int randomLoan = randomizer();
    cout << randomLoan << " is the random load taken by " << username <<"\n";
    

    user1.takeLoan(randomLoan, 5.0);
    user2.takeLoan(10000, 6.25);
    user3.takeLoan(100000, 10.0);

    calculateInterest(user1.getPrinciple(), user1.getRate(),
                      user2.getPrinciple(), user2.getRate(),
                      user3.getPrinciple(), user3.getRate());
  
    std::vector<User> users = {user1, user2, user3};
    std::vector<User>::iterator it = users.begin();
    
    while(it != users.end())
    {
        if(it >= users.begin() && it < users.end())
        {
            std::cout << it->getName() << " " << it->getID() << " "<< it->getBalance() << " " << it->getPrinciple() << " " << it->getRate() << "\n";
        }
        else
        {
            cerr<<"Index out of range"<<endl;
        }
        advance(it, 1);
    }
    cout<< "Compare User2 and User3 for posterity: \n";
    comparison(user2, user3);

    delete userArr;
    userArr = nullptr;
}