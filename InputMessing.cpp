#include <iostream>
#include <string>
#include <random>
using namespace std;
/*
    Functions that deal with taking user input and messing around with it
*/

/*
    Overload an operator to use 
    Rule: OOP57
    Rule: EXP62
*/
class StringComparison{
    private: 
    int integer;
    
    public:
    StringComparison(int n)
    {
        integer = n;
    }
    //override the != operator
    void comparison(StringComparison &num1, StringComparison &num2)
    {
        if(num1 != num2)
        {
            std::cout << "Those numbers are not the same. Excellent!"<<endl;
        }else{
            std::cout<<"You entered 5 anyway?! I guess I can let it slide..."<<endl;
        }
    }
    bool operator!=(const StringComparison &rhs) const
    {
        return rhs.integer > integer;
    }
};


/*
    Polymorphic object with destructor
    OOP52
    Point to things that exist
    OOP55


struct Prime{
    int myNum;
    int randNum;
    virtual void child();

    virtual ~Prime() = default;

    virtual void printFunc()
    {
        std::cout<< myNum;
    }

    virtual void printMyRand()
    {
        std::cout<< randNum;
    }
};
*/
/*
static void(Prime::*functionPointer)() = &Prime::printFunc;

void callPointer(Prime *pointer)
{
    (pointer->*functionPointer)();
}

void child(){
    Prime *offspring = new Prime;
    callPointer(offspring);
    delete offspring;
}
*/
/*
    returns a random value between 0 and 100
    MSC50
*/
int randomizer()
{
    
    static std::random_device rd;
    
    mt19937 engine(rd);
    uniform_int_distribution<int> dist(0,100);
    return dist(engine);
}
