class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass&); // private copy constructor
    NoCopyClass& operator=(const NoCopyClass&); // private copy assignment operator
public:
    NoCopyClass() { }
};

int main() {
    NoCopyClass obj1;
    // NoCopyClass obj2 = obj1; // Attempting to copy will result in a compiler error
    // NoCopyClass obj3;
    // obj3 = obj1; // Attempting to copy will result in a compiler error
    
    return 0;
}
class NoCopyClass {
public:
    NoCopyClass() { }
    NoCopyClass(const NoCopyClass&) = delete; // deleted copy constructor
    NoCopyClass& operator=(const NoCopyClass&) = delete; // deleted copy assignment operator
};

int main() {
    NoCopyClass obj1;
    // NoCopyClass obj2 = obj1; // Attempting to copy will result in a compiler error
    // NoCopyClass obj3;
    // obj3 = obj1; // Attempting to copy will result in a compiler error
    
    return 0;
}
