class MyClass {
private:
    MyClass(const MyClass& other) = delete;
    MyClass& operator=(const MyClass& other) = delete;
};
