//Use valid iterator ranges

#include <iostream>
#include <algorithm>
#include <vector>

/* The original code example, we could simply switch the c.end and c.begin to make it compliant with the rule
std::for_each(c.begin(), c.end(), ........)*/

void increment(int &i)
{
    ++i;
}

void func(std::vector<int> &c)
{
    if (c.size() >= 4) 
    {
        auto start = c.begin() + 1;
        auto end = c.begin() + 4;

        std::for_each(start, end, increment);
    }
    
    for (int i : c)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::vector<int> my_vector = {0, 1, 2, 3, 4, 5};
    func(my_vector);
    return 0;
}