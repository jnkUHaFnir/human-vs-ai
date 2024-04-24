    typedef struct person {
      unsigned age;
      char sex;
      size_t size;
      char name[];
    } person;
    
    inline
    person* alloc_person(int a, char s, size_t n) {
      size_t total = sizeof(person) + n;
      return memcpy(calloc(total, 1),
                    &(person const){ .age = a, .sex = s, .size = n},
                    sizeof(person));
    }