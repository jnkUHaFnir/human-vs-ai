class NonCopyableClass {
private:
    NonCopyableClass(const NonCopyableClass&); // private copy constructor
    NonCopyableClass& operator=(const NonCopyableClass&); // private copy assignment operator
public:
    NonCopyableClass() {
        // constructor implementation
    }
    
    // other member functions
};
