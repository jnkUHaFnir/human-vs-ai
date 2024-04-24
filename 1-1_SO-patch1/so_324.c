    struct StringArray
    {
        char** arr;
        size_t len = 0;
    };
    StringArray StringArray_init(char** arr = NULL, size_t len = NULL)
    {
        StringArray a; a.arr = arr; a.len = len ;
    }
    
    void StringArray_push(StringArray &a, char* str)
    {
        if(len == 0)
        {
            a = StringArrayInit(malloc(sizeof(char*)), 1);
        }
        else
        {
            a.len++;
        }
        a.arr = realloc(a.arr, len * sizeof(char*));
        a.arr[a.len - 1] = malloc((strlen(str) + 1) * sizeof(char));
        strcpy(a.arr[a.len - 1], str);
    }
    void StringArray_free(StringArray &a)
    {
        for(size_t i = 0; i < a.len; ++i)
            free(a.arr[i]);
        a = StringArray_init();
    }
    StringArray szArr = StringArray_init();
    StringArray_push(szArr, "This is a string.");
    StringArray_free(szArr);