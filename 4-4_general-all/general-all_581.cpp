class NonCopyableClass {
private:
    NonCopyableClass(const NonCopyableClass&); // Copy constructor declared as private
    NonCopyableClass& operator=(const NonCopyableClass&); // Copy assignment operator declared as private
public:
    NonCopyableClass() { } // Default constructor
    // Other member functions
};

int main() {
    NonCopyableClass obj1;
    // NonCopyableClass obj2 = obj1; // This will result in a compilation error due to copy constructor being private
    // NonCopyableClass obj3;
    // obj3 = obj1; // This will result in a compilation error due to copy assignment operator being private

    return 0;
}
