#include <iostream>
#include <stdexcept>
using namespace std;

class BaseException : public exception{
    public:
        const char* what() const noexcept override{
            return "Base Exception";
        }
};

class DerivedException : public BaseException{
    public:
        const char* what() const noexcept override{
            return "Derived Exception";
        }
};

int main()
{
    try{
        throw DerivedException();
    }
    catch(DerivedException& e)
    {
        cout<<"Caught Derived Exception: "<<e.what()<<endl;
    }
    catch(BaseException& e)
    {
        cout<<"Caught Base Exception: "<<e.what()<<endl;
    }
    catch(exception& e)
    {
        cout<<"Caught Exception: "<<e.what()<<endl;
    }

    return 0;
}