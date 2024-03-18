#include <iostream>
#include <stdexcept>
using namespace std;

void myFunction() noexcept;

void driverMyFunction();

int main(){
    try{
        driverMyFunction();
    }
    catch(const exception& e){
       cerr<<"Caught excpetion: "<<e.what()<<endl;
    }

    return 0;
}

void myFunction() noexcept{
    cout<<"Peforming my function"<<endl;
}

void driverMyFunction(){
    cout<<"Calling my function"<<endl;
    myFunction();
    cout<<"my function completed successfully."<<endl;
}