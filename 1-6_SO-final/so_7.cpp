    class person
    {
        std::string name;
        int age;
    public:
        person(const std::string& name, int age) : name(name), age(age)
        {
        }
        // 1. copy constructor
        person(const person& that) : name(that.name), age(that.age)
        {
        }
        // 2. copy assignment operator
        person& operator=(const person& that)
        {
            name = that.name;
            age = that.age;
            return *this;
        }
        // 3. destructor
        ~person()
        {
        }
    };