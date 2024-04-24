    class person
    {
        char* name;
        int age;
    public:
        // the constructor acquires a resource:
        // in this case, dynamic memory obtained via new[]
        person(const char* the_name, int the_age)
        {
            name = new char[strlen(the_name) + 1];
            strcpy(name, the_name);
            age = the_age;
        }
        // the destructor must release this resource via delete[]
        ~person()
        {
            delete[] name;
        }
    };