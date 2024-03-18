#include <iostream>

struct Parent{
    virtual ~Parent() = default;
    virtual void exampleFunction()
    {
        std::cout<<"We did it!\n";
    }
};

static void(Parent::*functionPointer)() = &Parent::exampleFunction;

void callPointer(Parent *pointer)
{
    (pointer->*functionPointer)();
}
/**
 * @brief Create a polymorphic child and delete it when we are done with it
 * 
 */
void child(){
    Parent *offspring = new Parent;
    callPointer(offspring);
    /*
        Now we actually delete that offspring
    */
    delete offspring;
}

int main(){
    child();
}