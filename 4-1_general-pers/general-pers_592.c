#include <stdio.h>
#include <string.h>

#define MAX_SUBSTRINGS 10
#define MAX_SUBSTRING_LENGTH 10

int main() {
    char *str1 = "k__hi;s__bye;example";
    char *s1;
    char arr[MAX_SUBSTRINGS][MAX_SUBSTRING_LENGTH];
    char temp[MAX_SUBSTRING_LENGTH];
    int i, j, n = 0;

    s1 = strtok(str1, ";");
    while (s1 != NULL) {
        if (strncmp(s1, "s__", 3) == 0) {
            if (n < MAX_SUBSTRINGS) {
                strncpy(arr[n++], s1, MAX_SUBSTRING_LENGTH - 1);
            } else {
                printf("Exceeded maximum number of substrings\n");
                break;
            }
        }
        s1 = strtok(NULL, ";");
    }

    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    for (i = 0; i < n; ++i) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
