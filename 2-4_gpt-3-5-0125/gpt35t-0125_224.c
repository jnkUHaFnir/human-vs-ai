#define MYNEW(Type, Allocator, Args...) Allocator->Alloc<Type>(sizeof(Type), Args);

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args... args)
{
    return TypeFactory<Type>::Create(args...);
}

template<typename Type>
class TypeFactory
{
public:
    template<typename... Args>
    static Type* Create(Args... args)
    {
        return new Type(args...);
    }
};
