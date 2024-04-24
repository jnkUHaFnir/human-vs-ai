class MyNonCopyableClass {
private:
    MyNonCopyableClass(const MyNonCopyableClass&); // private copy constructor
    MyNonCopyableClass& operator=(const MyNonCopyableClass&); // private copy assignment operator
public:
    MyNonCopyableClass() { // default constructor
        // constructor implementation
    }
};
