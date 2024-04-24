class NonCopyable {
private:
    NonCopyable(const NonCopyable&); // Declare copy constructor as private
    NonCopyable& operator=(const NonCopyable&); // Declare copy assignment operator as private
public:
    NonCopyable() {
        // Constructor
    }
};

int main() {
    NonCopyable obj1;
    // NonCopyable obj2 = obj1; // This will cause a compilation error due to private copy constructor
    // NonCopyable obj3;
    // obj3 = obj1; // This will cause a compilation error due to private copy assignment operator
    return 0;
}
