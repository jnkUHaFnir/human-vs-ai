class NonCopyable {
private:
    NonCopyable(const NonCopyable& other); // declare copy constructor as private
    NonCopyable& operator=(const NonCopyable& other); // declare copy assignment operator as private

public:
    NonCopyable() {
        // Constructor implementation
    }

    // Other member functions
};

int main() {
    NonCopyable obj1;
    // NonCopyable obj2 = obj1; // This would give a compile-time error
    // NonCopyable obj3;
    // obj3 = obj1; // This would also give a compile-time error

    return 0;
}
