class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass &other) = delete; // Delete copy constructor
    NoCopyClass& operator=(const NoCopyClass &other) = delete; // Delete copy assignment operator
};
