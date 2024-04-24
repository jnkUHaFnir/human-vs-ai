class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass &other); // Prevent copying by making copy constructor private
    NoCopyClass& operator=(const NoCopyClass &other); // Prevent copying by making copy assignment operator private
};
