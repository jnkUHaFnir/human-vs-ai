class NonCopyable {
private:
    // Declare the copy constructor and copy assignment operator as private without implementation.
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
public:
    NonCopyable() {}
};

int main() {
    NonCopyable obj1;
    // NonCopyable obj2 = obj1; // This will result in a compilation error.
    // NonCopyable obj3;
    // obj3 = obj1; // This will result in a compilation error.
    
    return 0;
}
