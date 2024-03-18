#include <iostream>

class SamepleRuleCode{

    public:
    int integer;
    void comparison();
    /**
     * @brief overload the != operator to be used on our objects
     * 
     * @param rhs 
     * @return true 
     * @return false 
     */
    bool operator!=(const SamepleRuleCode &rhs) const{
        return rhs.integer > integer;
    }
};
/**
 * @brief compare two numbers using the overloaded operator
 * 
 * @param num1 
 * @param num2 
 */
void comparison(const SamepleRuleCode &num1, const SamepleRuleCode &num2)
{
    if(num1 != num2)
    {
        std::cout << "These numbers are not the same!\n";
    }else{
       std::cout << "These numbers are the same!\n"; 
    }
}

int main()
{
    SamepleRuleCode firstNum;
    SamepleRuleCode secNum;
    firstNum.integer = 1;
    secNum.integer = 2;
    comparison(firstNum, secNum);
}