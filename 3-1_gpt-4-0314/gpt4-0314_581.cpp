class NonCopyable {
public:
    // Other constructors and member functions here

    // Delete the copy constructor and copy assignment operator
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};
