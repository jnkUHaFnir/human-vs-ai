class NonCopyableClass {
private:
    NonCopyableClass(const NonCopyableClass& other);
    NonCopyableClass& operator=(const NonCopyableClass& other);
public:
    // Constructor, destructor, and other member functions
};
