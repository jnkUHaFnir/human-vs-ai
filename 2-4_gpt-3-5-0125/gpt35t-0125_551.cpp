template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}

// Example usage
MYNEW_1(Vector<int>, MyAllocator, 10, 20, 30); // Allocate a Vector<int> with constructor arguments 10, 20, 30
