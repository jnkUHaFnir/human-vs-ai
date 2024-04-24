    char *flip_string(const char *string)
    {
        char *tmp = NULL;
        size_t len = strlen(string);
        int i = 0;
        /*
         * Don't forget that strlen() returns the length of the string
         * **WITHOUT** counting the ending '\0' character.
         * Thus, you have to add the extra space when you're allocating
         */
        if (NULL == (tmp = malloc(sizeof (char) * (len + 1))) {
            printf("Allocation failed ...\n");
            return NULL;
        }
        /*
         * The newly created string must have an ending character
         * Which is '\0'
         */
        
        tmp[len] = '\0';
        
        /*
         * Here, you want to reverse the "true content" of your string.
         * That is why you ignore the ending '\0' of the string by
         * setting the upper bound to strlen (with a strict '<') **AND**
         * it is also the reason a '- 1' just pops in the index choice.
         */
        for(i = 0; i < len; i++) {
            tmp[i] = string[len - i - 1];
        }
        return tmp;
    }