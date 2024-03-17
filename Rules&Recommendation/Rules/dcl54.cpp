//Overload allocation and deallocation functions as a pair in the same scope

#include <Windows.h>
#include <new>

void *operator new(std::size_t size) noexcept(false)
{
    static HANDLE heap = ::HeapCreate(0, 0, 0);
    if (heap)
    {
        void* p = ::HeapAlloc(heap, 0, size);
        if (p)
        {
            return p;
        }
    }
    throw std::bad_alloc();
}

void *operator delete(void* ptr) noexcept
{
    static HANDLE heap = ::GetProcessHeap();

    if (!ptr) 
    {
        return;
    }

    if (!::HeapFree(heap, 0, ptr)) 
    {

    }
}

int main()
{
    try
    {
        int* p = new int;
        delete p;
    }
    catch (const std::bad_alloc& e)
    {
        std::exit(EXIT_FAILURE);
    }
    return 0;
}