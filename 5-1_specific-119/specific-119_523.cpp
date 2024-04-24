class MyClass {
private:
    MyClass(const MyClass& other) = delete; // Prevent copy construction
    MyClass& operator=(const MyClass& other) = delete; // Prevent copy assignment
};
