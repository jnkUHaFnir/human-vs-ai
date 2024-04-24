        // 1. copy constructor
        person(const person& that)
        {
            name = new char[strlen(that.name) + 1];
            strcpy(name, that.name);
            age = that.age;
        }
        // 2. copy assignment operator
        person& operator=(const person& that)
        {
            if (this != &that)
            {
                delete[] name;
                // This is a dangerous point in the flow of execution!
                // We have temporarily invalidated the class invariants,
                // and the next statement might throw an exception,
                // leaving the object in an invalid state :(
                name = new char[strlen(that.name) + 1];
                strcpy(name, that.name);
                age = that.age;
            }
            *return this;
        }