#include <iostream>
#include <string>
#include "Bank.cpp"
#include "InputMessing.cpp"
using namespace std;

int main() {
    int principle = 10000;
    int time = 7;
    float rate = 6.25;

    float result = conSimpleInterest(principle, time, rate);
    cout << result << "\n";

    //STR50
    string userInput;
    cout << "Input a string: \n";
    cin >> userInput;
    while(1)
    {
        //STR51
        if(userInput == "")
        {
            cin.clear();
            cout<<"Null Input, please enter a string"<< endl;
            cin>>userInput;
        }else{
            break;
        }
    }
    cout << "Input a number that isnt 5: \n";
    int number;
    cin >> number;
    while(1)
    {
        if(userInput == "")
        {
            cin.clear();
            cout<<"Null Input, please enter a number that isnt 5"<< endl;
            cin>>userInput;
        }else{
            break;
        }
    }

    StringComparison comparator1(number);
    StringComparison comparator2(5);
    comparator1.comparison(comparator1, comparator2);
    /*
    Prime prime;
    prime.myNum = 1;
    prime.randNum = randomizer();
    */
    


}