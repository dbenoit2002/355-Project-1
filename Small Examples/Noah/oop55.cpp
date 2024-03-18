#include <iostream>
/**
 * @brief Create a struct with a simple function
 * 
 */
struct Parent{
    virtual ~Parent() = default;
    virtual void exampleFunction()
    {
        std::cout<<"We did it!\n";
    }
};

static void(Parent::*functionPointer)() = &Parent::exampleFunction;

/**
 * @brief Call a generic pointer to the function in the parent struct
 * 
 * @param pointer 
 */
void callPointer(Parent *pointer)
{
    (pointer->*functionPointer)();
}
/**
 * @brief Create a polymorphic child, call its function which calls a pointer that is a 
 * member of that function
 * 
 */
void child(){
    Parent *offspring = new Parent;
    callPointer(offspring);
}

int main(){
    child();
}