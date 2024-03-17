//Do not access an object outside of its lifetime

#include <iostream>

struct S
{
    void mem_func()
    {

    }
};

void f()
{
    S s;
    s.mem_func();
}

int main()
{
    f();

    return 0;
}