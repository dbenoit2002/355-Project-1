//A lambda object must not outlive any of its reference captured objects

#include <iostream>
#include <functional>
#include <memory>

std::function<int()> g() 
{
    auto i = std::make_shared<int>(12);
    return [i]() mutable
    {
        *i = 100;
        return *i;
    };
}

void f()
{
    auto func = g();
    int j = func();
    std::cout << "j: " << j << std::endl;
}

int main()
{
    f();
    return 0;
}
