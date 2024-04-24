// Allocator.h

#include <iostream>
#include <cstdlib>
#include <utility>
#include <new>

class Allocator
{
public:
    template <typename Type, typename... Args>
    Type* Alloc(unsigned int size, Args&&... args);

};

// Allocator.cpp

#include "Allocator.h"

template <typename Type, typename... Args>
Type* Allocator::Alloc(unsigned int size, Args&&... args)
{
    void* rawMemory = std::malloc(size);

    if (!rawMemory)
    {
        throw std::bad_alloc();
    }

    Type* object = new (rawMemory) Type(std::forward<Args>(args)...);

    return object;
}

// To force the instantiation of the Alloc() function for certain types
template Type* Allocator::Alloc<int>(unsigned int, int); // for example
#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS__);
Allocator* allocator = new Allocator();

// Allocate an object with no arguments for the constructor
auto pointer1 = MYNEW(int, allocator);

// Allocate an object with 1 argument for the constructor
auto pointer2 = MYNEW(std::string, allocator, "Hello world!");

// Allocate an object with 2 arguments for the constructor
auto pointer3 = MYNEW(std::pair<int, float>, allocator, 42, 3.14f);
