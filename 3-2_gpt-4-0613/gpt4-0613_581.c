class MyClass {
public:
   MyClass (const MyClass &old_obj);
};
class MyClass {
public:
   MyClass& operator= (const MyClass &old_obj);
};
class MyClass {
public:
   MyClass (const MyClass &old_obj) = delete;
   MyClass& operator= (const MyClass &old_obj) = delete;
};
