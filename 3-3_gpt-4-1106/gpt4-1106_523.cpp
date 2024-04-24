class NonCopyable {
public:
    NonCopyable(const NonCopyable&) = delete; // Delete copy constructor
    NonCopyable& operator=(const NonCopyable&) = delete; // Delete copy assignment operator

    // Other constructors and methods...
};
