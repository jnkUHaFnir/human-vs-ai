
2. **Copy Assignment Operator**: The copy assignment operator is used when an existing object is assigned the value of another existing object of the same type.

```c++
class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        // Copy assignment operator
        return *this;
    }
};

MyClass obj1, obj2;
obj2 = obj1; // Copy assignment operator is called here
