#include <iostream>
#include<cstring>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include "Bank.cpp"
#include "User.cpp"
#include "Randomizer.cpp"

using namespace std;

enum { MIN_SIZE_ALLOWED = 10 };

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

void printCharArray(char *ptr, size_t number) { //Recommendation MEM00

    int* list = (int*) malloc(number * sizeof(int));
    if(ptr == NULL) {
        cerr<<"No memory allocated to ptr"<<endl;
    }
    if(number >= MIN_SIZE_ALLOWED) {
        for(int i = 0; i < number; i++) {
            list[i] = ptr[i];
        }
    }
    else {
        cerr<<"The size of array ptr is less than the minimum allowed size for an array"<<endl;
        free(list);
        return;
    }
    for(int i = 0; i < number; i++) {
        cout<<list[i]<<"\n"<<endl;
    }
    free(list);
}

void mainPrint() //Rule EXP60
{
    Printing printing;
    callPrint(printing);
}

int main() {

    mainPrint();

    //Rule FIO50
    const string &fileName = "Banned Users.txt";
    fstream file(fileName);

    if(!file.is_open()) {
        cerr<<"Could not open file"<<endl;
        return 1;
    }
    string line;
    string fileStr = "";

    file.seekg(0, ios::beg);
    while(getline(file, line)) {
        cout<<line<<endl;
        fileStr = fileStr + line;
    }

    //Recommendation STR06
    char *token;
    char str[] = "This is the main for our bank!";
    printCharArray(str, strlen(str));
    
    void *ptr = (char *)malloc(strlen(str) + 1); //Rule MEM53
    char *copy = new (ptr) char;
    if(copy == NULL){
        cerr<<"The copied string is empty"<<endl;
        exit(1);
    }
    strcpy(copy, str);
    token = strtok(copy," ,");

    while(token!=NULL){
        cout<<token<<endl;
        token = strtok(NULL," ,");
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
  
    std::vector<User> users(3); // Rule CTR52
    users.emplace_back(user1);
    users.emplace_back(user2);
    users.emplace_back(user3);
    //= {user1, user2, user3};
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

    delete[] userArr; // Using delete[] on userArr is rule MEM51
    userArr = nullptr;

    free(ptr);
    ptr = NULL;
}