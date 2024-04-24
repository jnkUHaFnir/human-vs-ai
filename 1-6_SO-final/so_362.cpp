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