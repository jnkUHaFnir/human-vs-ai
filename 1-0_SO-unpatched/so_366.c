    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #define STR_LEN 1000
    void read_line(char *str, size_t n);
    int extract(const char *str, char *dest);
    int main(void) {
        char instr[STR_LEN + 1];
        char outstr[STR_LEN + 1];
    
        printf("Please enter a URL: ");
        read_line(instr, sizeof(instr));
        if (extract(instr, outstr)) {
            puts(outstr);
        } else {
            printf("Web address starting with www. and ending with .edu not found\n");
        }
        return 0;
    }
    int read_line(char *str, size size) {
        int ch;
        size_t i = 0;
        while ((ch = getchar()) != EOF && c != '\n') {
            if (i + 1 < n) {
                str[i++] = ch;
            }
        }
        str[i] = '\0';
        return (ch == EOF && i == 0) ? EOF : i;
    }
    int extact(const char *str, char *dest) {
        const char *p;
        *dest = '\0';
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
            size_t len = strcspn(p, "/ \n");  // compute length of website name
            if (len > 8 && !memcmp(p + len - 4, ".edu", 4)) {
                // copy website name, assuming dest is at least as large as str
                strncat(dest, p, len);
                return 1;
            }
            str = p + len;
        }
        return 0;
    }