    #include <string.h>
    int pass_check(const char *str) {
        const char *p;
        for (;;) {
            if ((p = strstr(str, "https://www.")) != NULL) {
                p += 8;  // skip the https:// prefix
            } else 
            if ((p = strstr(str, "http://www.")) != NULL) {
                p += 7;  // skip the http:// prefix
            } else {
                break;
            }
            // URL starts with www.
            int len = strcspn(p, "/ \n");  // compute length of website name
            if (len > 8 && !memcmp(p + len - 4, ".edu", 4)) {
                // print website name
                printf("%.*s\n", len, p);
                return 1;
            }
            str = p + len;
        }
        printf("Web address starting with www. and ending with .edu not found\n");
        return 0;
    }