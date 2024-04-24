class NoCopy {
public:
    NoCopy() = default;

    // Delete copy constructor
    NoCopy(const NoCopy& other) = delete;

    // Delete copy assignment operator
    NoCopy& operator=(const NoCopy& other) = delete;
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // Error: copy constructor is deleted
    // NoCopy obj3;
    // obj3 = obj1; // Error: copy assignment operator is deleted

    return 0;
}
