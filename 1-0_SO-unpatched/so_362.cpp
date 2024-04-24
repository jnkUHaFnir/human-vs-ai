    // 2. copy assignment operator
    person& operator=(const person& that)
    {
        char* local_name = new char[strlen(that.name) + 1];
        // If the above statement throws,
        // the object is still in the same state as before.
        // None of the following statements will throw an exception :)
        strcpy(local_name, that.name);
        delete[] name;
        name = local_name;
        age = that.age;
        return *this;
    }