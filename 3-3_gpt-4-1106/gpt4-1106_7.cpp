class NonCopyable {
public:
    NonCopyable() = default; // Use the default constructor

    // Delete the copy constructor and the copy assignment operator
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    // ... other members ...
};
