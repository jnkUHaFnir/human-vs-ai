ClassName(const ClassName &other);
ClassName& operator=(const ClassName &other);
private:
    ClassName(const ClassName &other);
    ClassName& operator=(const ClassName &other);

    // OR in C++11 and later
    ClassName(const ClassName &other) = delete;
    ClassName& operator=(const ClassName &other) = delete;
