//Guarantee that mutually visible identifiers are unique

#include <iostream>

namespace UniqueNamespace 
{
    // Declaration of extern variables
    int extVarUniqueNameA = 0;
    int extVarUniqueNameB = 0;
}

int main() 
{
    UniqueNamespace::extVarUniqueNameA = 5;
    UniqueNamespace::extVarUniqueNameB = 10;
    
    std::cout << "extVarUniqueNameA: " << UniqueNamespace::extVarUniqueNameA << std::endl;
    std::cout << "extVarUniqueNameB: " << UniqueNamespace::extVarUniqueNameB << std::endl;

    return 0;
}
