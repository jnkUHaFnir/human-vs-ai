    typedef struct person {
      unsigned age;
      char sex;
      size_t size;
      char name[];
    } person;
    
    inline
    person* alloc_person(int a, char s, size_t n) {
      person * ret = calloc(sizeof(person) + n, 1);
      if (ret) memcpy(ret,
                      &(person const){ .age = a, .sex = s, .size = n},
                      sizeof(person));
      return ret;
    }