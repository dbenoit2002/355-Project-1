//Use valid references, poinmters, and interators to reference elements of a container

#include <iostream>
#include <deque>

void f(const double *items, std::size_t count)
{
    std::deque<double> d;

    for (std::size_t i = 0; i < count; ++i)
    {
        d.push_back(items[i] + 41.0);
    }

    for (const auto& value : d) 
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main()
{
    double my_items[] = {1.0, 2.0, 3.0};
    std::size_t count = sizeof(my_items) / sizeof(double);

    f(my_items, count);

    return 0;
}
