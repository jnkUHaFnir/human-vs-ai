    struct StringArray
    {
        char** arr;
        size_t len = 0;
    };
    StringArray StringArray_init()
    {
        StringArray a; a.arr = NULL; a.len = 0;
    }
    
    void StringArray_push(StringArray &a, size_t size, char* str)
    {
        a.arr[a.len] = malloc((strlen(str) + 1) * sizeof(char));
        strncpy();
    }
    void StringArray_free(StringArray &a)
    {
        for(size_t i = 0; i < a.len; ++i)
            free(a.arr[i]);
        a = StringArray_init();
    }
    StringArray szArr = StringArray_init();
    StringArray_push(szArr, "This is a string");
    StringArray_free(szArr);