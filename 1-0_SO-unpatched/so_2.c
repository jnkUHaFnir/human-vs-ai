    #define DEFAULT_LEN 10
    void allocate(str1 *p1, const char * str) {
        char * array;
        if(str) {
            //(char *) is omittable in C (not C++)
            array = malloc(strlen(str));
            strcpy(array, str);
        }
        else {
            array = malloc(DEFAULT_LEN);
            array[0] = 0;
        }
        p1->array = array;
    }