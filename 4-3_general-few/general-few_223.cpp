#define MYNEW(Type, Allocator) Allocator->Alloc<Type>(sizeof(Type));`

template<typename Type>
Type* Alloc(unsigned int size) // Allocator::Alloc<Type>
{
    return (Type*)new(malloc(reportedSize)) Type;
}

#define MYNEW_1(Type, Allocator, ConVar1) Allocator->Alloc<Type>(sizeof(Type), ConVar1);`

template<typename Type, typename ConVarType>
Type* Alloc(unsigned int size, ConVarType Convar1) // Allocator::Alloc<Type>
{
    return (Type*)new(malloc(reportedSize)) Type(Convar1);
}

// Custom allocator function for types without default constructors
template<typename Type, typename ConVar1Type>
Type* AllocWithConstructor(unsigned int size, ConVar1Type Convar1) // Allocator::AllocWithConstructor<Type>
{
    return (Type*)new(malloc(reportedSize)) Type(Convar1); 
}

