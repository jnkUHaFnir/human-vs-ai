ClassName(const ClassName &other);
ClassName& operator=(const ClassName &other);
class NoCopy {
private:
    // Declare but do not implement copy constructor and copy assignment operator
    NoCopy(const NoCopy &);
    NoCopy& operator=(const NoCopy &);

public:
    NoCopy() {
        // Constructor implementation
    }

    // Other member functions
};

