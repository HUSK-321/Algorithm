#include <stdlib.h>
#include <memory>

class Base{
public:
    static void * operator new(std::size_t size) throw(std::bad_alloc);
    static void operator delete(void *rawMemory, std::size_t size) throw();
    //...
};

void Base::operator delete(void *rawMemory, std::size_t size) throw(){
    if(rawMemory == 0)  return;

    if(size != sizeof(Base)){
        ::operator delete(rawMemory);
        return;
    }

    rawMemory 가 가리키는 메모리 비할당
    return;
}