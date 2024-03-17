//Implement abstract data types using opaque types

#include <iostream>
#include <cstring> 

class ManagedString {
private:
    char *cstr;

public:
    ManagedString(const char* str) {
        cstr = new char[strlen(str) + 1];
        strcpy(cstr, str);
    }

    ~ManagedString() {
        delete[] cstr;
    }

    void strcpy_m(const ManagedString& other) {
        strcpy(cstr, other.cstr);
    }

    void strcat_m(const ManagedString& other) {
        strcat(cstr, other.cstr);
    }

    const char* get() const {
        return cstr;
    }
};

int main() {
    ManagedString s1("Hello");
    ManagedString s2("World");

    s1.strcpy_m(s2);
    std::cout << "After strcpy_m: " << s1.get() << std::endl;

    s1.strcat_m(s2);
    std::cout << "After strcat_m: " << s1.get() << std::endl;

    return 0;
}
