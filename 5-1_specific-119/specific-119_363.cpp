class NonCopyable {
private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
    
public:
    NonCopyable() { }
    // Other member functions...
};

int main() {
    NonCopyable obj1;
    // NonCopyable obj2 = obj1; // This will fail to compile
    // NonCopyable obj3;
    // obj3 = obj1; // This will fail to compile
    return 0;
}
