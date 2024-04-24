#define MYNEW(Type, Allocator, InitFunc) Allocator->Alloc<Type>(sizeof(Type), InitFunc);
template<typename Type, typename InitFuncType>
Type* Alloc(unsigned int size, InitFuncType InitFunc) // Allocator::Alloc<Type>
{
    Type* obj = (Type*)malloc(size);
    if (obj) {
        InitFunc(obj);
    }
    return obj;
}
MYNEW(MyType, myAllocator, [](MyType* ptr){ new (ptr) MyType(arg1, arg2); });
