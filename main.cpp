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
    


}