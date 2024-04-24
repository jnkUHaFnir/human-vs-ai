class NonCopyable {
public:
    NonCopyable(const NonCopyable&) = delete; // Copy constructor
    NonCopyable& operator=(const NonCopyable&) = delete; // Copy assignment operator
    NonCopyable() = default; // Default constructor
};
