// Allocator header
class Allocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(unsigned int size, Args&&... args) {
        void* mem = malloc(size);
        if (mem == nullptr) {
            return nullptr;
        }
        return new(mem) Type(std::forward<Args>(args)...);
    }
};
// Usage with custom allocator
Allocator* myAllocator = new Allocator();
Type* obj1 = myAllocator->Alloc<Type>(sizeof(Type));
Type* obj2 = myAllocator->Alloc<Type>(sizeof(Type), arg1, arg2); // Passing constructor arguments
