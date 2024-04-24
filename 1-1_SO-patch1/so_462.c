    char* removeDup(char *string)
    {
        int i, c = 0;
        size_t string_len = strlen(string);
        char *newString = malloc(string_len + 1);
    
        for (i = 0; i < string_len; i++) {
            if (string[i] != string[i + 1]) {
                newString[c++] = string[i];
            }
        }
        newString[c] = '\0';
    
        return newString;
    }
    
    #define MAX_STRING_LEN 80
    void Ex6() {
        char string[MAX_STRING_LEN];
        char* result;
    
        fgets(string, MAX_STRING_LEN, stdin);
        result = removeDup(string);
    
        printf("%s", result);
        free(result);
    }