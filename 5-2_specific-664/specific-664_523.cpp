class NoCopy {
private:
    NoCopy(const NoCopy& other); // Declare copy constructor as private
    NoCopy& operator=(const NoCopy& other); // Declare copy assignment operator as private
public:
    NoCopy() {}
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // Error: Copy constructor is private
    // NoCopy obj3;
    // obj3 = obj1; // Error: Copy assignment operator is private
    
    return 0;
}
