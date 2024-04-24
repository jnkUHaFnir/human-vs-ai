template<typename Type, typename... Args>
Type* MyNew(Allocator* allocator, Args&&... args)
{
    void* rawMemory = allocator->Alloc(sizeof(Type));
    return new(rawMemory) Type(std::forward<Args>(args)...);
}
