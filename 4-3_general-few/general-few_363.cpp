class NoCopyClass {
private:
    // Declare but do not define the copy constructor and copy assignment operator
    NoCopyClass(const NoCopyClass&);
    NoCopyClass& operator=(const NoCopyClass&);
public:
    NoCopyClass() {}
};
class NoCopyClass {
public:
    NoCopyClass() {}

    // Explicitly delete the copy constructor and copy assignment operator
    NoCopyClass(const NoCopyClass&) = delete;
    NoCopyClass& operator=(const NoCopyClass&) = delete;
};
