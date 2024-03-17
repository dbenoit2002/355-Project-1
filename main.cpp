#include <iostream>
#include<cstring>
/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>*/
#include <fstream>
#include <array>
#include <vector>
#include "Bank.cpp"
#include "User.cpp"
#include "Randomizer.cpp"

using namespace std;

User* createUsers() {       
    std::aligned_storage<sizeof(User[10]), alignof(User[10])>::type buffer; //MEM54
    //OOP55 and EXP54
    User* arrptr = ::new (&buffer) User[10];
    if(!arrptr) { //MEM52
        std::cout << "Could not create userArr";
        return nullptr;
    }
    return arrptr;
}

User* createUsersHelper() { //ERR58 and part of EXP54
    try {
        return createUsers();
    } catch (...) {
        std::cout << "An exception occured";
        return nullptr;
    }
}

User* userArr = createUsersHelper();

/*void checkBannedUsers(vector<string> bannedVec, string name)
{
    int i = 0;
    
    while(i < bannedVec.size() && name != bannedVec[i])
    {
        i++;
    }

    if(name == bannedVec[i])
    {
        cout<<"This user is banned"<<endl;
    }
}*/

int main() {

    //Rule FIO50 & recommendation STR06
    const string &fileName = "Banned Users.txt";
    fstream file(fileName);

    if(!file.is_open()) {
        cerr<<"Could not open file"<<endl;
        return 1;
    }
    string line;

    file.seekg(0, ios::beg);
    while(getline(file, line)) {
        cout<<line<<endl;
    }

    //CTR51
    std::vector<User> users(4); //defining vector size is rule CTR52

    users.emplace_back("User 1", 1);
    users.emplace_back("User 2", 2);
    users.emplace_back("User 3", 3);

    for (auto it = users.begin(); it != users.end(); ++it) 
    {
        std::cout << it->getName() << " has ID " << it->getID() << std::endl;
        
    }

    //New user, safe to do
    users.emplace_back("User 4", 4);

    for (auto it = users.begin(); it != users.end(); ++it) 
    {
        //Access the elements
        std::cout << it->getName() << " has ID " << it->getID() << std::endl;
        
    }
    
    
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
        std::cout << "Null value found. Defaulting...\n";
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
  
    //std::vector<User> users = {user1, user2, user3};
    std::vector<User>::iterator it = users.begin();
    
    while(it != users.end())
    {
        if(it >= users.begin() && it < users.end())
        {
            std::cout << it->getName() << it->getID() << it->getBalance() << it->getPrinciple() << it->getRate() << "\n";
        }
        else
        {
            cerr<<"Index out of range"<<endl;
        }
        advance(it, 1);
    }
    cout<< "Compare User2 and User3 for posterity: \n";
    comparison(user2, user3);

    // delete userArr;
    //EXP54
    //Destruct and deallocate userArr.
    for (int i = 0; i < 10; ++i) 
    {
        userArr[i].~User();
    }
    userArr = nullptr;
    delete[] userArr; // Using delete[] on userArr is rule MEM51
    /*delete[] str;
    free(copy);
    copy = NULL;*/

    return 0;
}
