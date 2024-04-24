#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 < *s2) {
            return -1;
        } else if (*s1 > *s2) {
            return 1;
        }
        s1++;
        s2++;
    }
    
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    } else if (*s1 == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    int result = my_strcmp(argv[1], argv[2]);

    printf("Value: %d \n", result);

    return 0;
}
