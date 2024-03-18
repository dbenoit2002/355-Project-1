#include <iostream>
#include <memory>
using namespace std;

class Info{
public:
    Info(int data) : data(data){
        cout<<"Info is constructed with data: "<<data<<endl;
    }
    ~Info(){
        cout<<"Info destructed, data: "<<data<<endl;
    }

    void doSomething(){
        cout<<"Does something with data: "<<data<<endl;
    }
private:
    int data;
};

int main()
{
    unique_ptr<Info> uniquePtr(new Info(34));

    shared_ptr<Info> sharedPtr1(new Info(99));
    shared_ptr<Info> sharedPtr2 = sharedPtr1;

    if(uniquePtr){
        uniquePtr->doSomething();
    }

    if(sharedPtr1){
        sharedPtr1->doSomething();
    }

    if(sharedPtr2){
        sharedPtr2->doSomething();
    }

    return 0;
}