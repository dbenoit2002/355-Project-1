//Do not substract iterators that do not refer to the same container

#include <iostream>
#include <vector>
#include <iterator>

template <typename Iterator>
bool isInSameContainerRange(Iterator first, Iterator last, Iterator test) 
{
    return (test >= first) && (test < last);
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto begin = numbers.begin(); 
    auto end = numbers.end(); 
    auto test = begin + 2;

    if (isInSameContainerRange(begin, end, test)) 
    {
        std::cout << "The element is within range, at position: " 
                  << std::distance(begin, test) << std::endl;
    } else 
    {
        std::cout << "The element is not within the specified range." << std::endl;
    }

    return 0;
}
