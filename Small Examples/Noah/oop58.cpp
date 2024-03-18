#include <iostream>

class Copier{

    public:
    int integer;
    Copier();
    /**
     * @brief Construct a new Copier object
     * 
     * @param s 
     */
    Copier(const Copier& s, const Copier& n)
    {
        std::cout<< "Copied!\n";
    }
};

int main()
{
    Copier val1;
    Copier val2;
    val1.integer = 1;
    Copier(val2, val1);
}