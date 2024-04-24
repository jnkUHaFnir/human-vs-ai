// Define a new macro with an additional parameter for initialization arguments
#define MYNEW_2(Type, Allocator, InitFunc) Allocator->Alloc<Type>(sizeof(Type), InitFunc);

// Modify the allocator template to accept an initialization function
template<typename Type, typename InitFunc>
Type* Alloc(unsigned int size, InitFunc initFunc) {
    Type* rawMemory = (Type*)malloc(size);
    if (rawMemory != nullptr) {
        initFunc(rawMemory);
    }
    return (Type*)new(rawMemory) Type; // Placement new with initialized memory
}

// Example of how you can use this modified allocator
struct Example {
    int a;
    float b;

    Example(int aVal, float bVal) : a(aVal), b(bVal) {}
};

void InitializeExample(Example* obj) {
    new(obj) Example(10, 3.14f); // Initialize Example object with specific values
}

int main() {
    Allocator* allocator = new Allocator(); // Initialize your custom allocator

    Example* exampleObj = MYNEW_2(Example, allocator, InitializeExample);
    
    // Use exampleObj...

    delete allocator; // Don't forget to free memory allocated by allocator

    return 0;
}
