    void allocate(str1 *p1, const char * str) {
        char * array = (char *)malloc(10 * sizeof(char));
        if(str) strcpy(array, str);
        p1->array = array;
    }