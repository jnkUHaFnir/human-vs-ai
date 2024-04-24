    class person
    {
        char* name;
        int age;
    public:
        person(const char* the_name, int the_age)    // easy to forget the const
        {
            name = new char[strlen(the_name) + 1];   // easy to forget the +1
            strcpy(name, the_name);    // easy to confuse the order of arguments
            age = the_age;
        }