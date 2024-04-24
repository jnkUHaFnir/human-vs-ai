class NonCopyable {
public:
    NonCopyable(const NonCopyable& other) = delete;             // Prevent copy construction
    NonCopyable& operator=(const NonCopyable& other) = delete;  // Prevent copy assignment
};
