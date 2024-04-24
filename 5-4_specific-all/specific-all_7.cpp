class NonCopyable {
private:
    NonCopyable(const NonCopyable&); // private copy constructor
    NonCopyable& operator=(const NonCopyable&); // private copy assignment operator
public:
    NonCopyable() { }
    // other constructors and member functions
};
