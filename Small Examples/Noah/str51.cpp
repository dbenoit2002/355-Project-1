#include <stdlib.h>
#include <string>
#include <iostream>
/**
 * @brief Search through the local environemt for a file with the id specified and validate it to make sure
 * we dont make a string from a null pointer
 * 
 */
void function()
{
    char* searchFor = std::getenv("TEMP");
    char* found;

    if(searchFor != NULL)
    {
        std::string found = searchFor;
        std::cout << "Found\n";
    }else{
        std::cout << "Not found\n";
    }
}

int main()
{
    function();
}