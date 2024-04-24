#include <stdio.h>

int my_strcmp(const char s1[], const char s2[]) {
    int i = 0;
    
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == '\0' && s2[i] != '\0') { 
            return -1; // s1 is shorter than s2
        } else if (s1[i] != '\0' && s2[i] == '\0') { 
            return 1; // s1 is longer than s2
        } else if (s1[i] < s2[i]) { 
            return -1; // s1 < s2
        } else if (s1[i] > s2[i]) { 
            return 1; // s1 > s2
        }
        
        i++;
    }

    return 0; // s1 and s2 are equal
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    int result = my_strcmp(argv[1], argv[2]);

    printf("Value: %d\n", result);

    return 0;
}
