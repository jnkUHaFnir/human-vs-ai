class NonCopyable {
public:
    NonCopyable(const NonCopyable&) = delete;            // Delete the copy constructor
    NonCopyable& operator=(const NonCopyable&) = delete; // Delete the copy assignment operator
};
