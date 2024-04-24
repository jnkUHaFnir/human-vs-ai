#include <stdio.h>
#include <string.h>

int main() {
    char *str1 = "s__def;s__abc;s__ghi;s__jkl;";
    char *s1, *st7;
    char arr[10][10] = {0};
    char temp[10];
    int i, j, len;

    s1 = strtok(str1, ";");
    do {
        st7 = strstr(s1, "s__");
        if (st7 != NULL) {
            strcpy(arr[i], st7);
        }
    } while ((s1 = strtok(NULL, ";")));

    // Bubble sort the strings in arr
    len = strlen(arr[0]); // Assuming all strings have the same length
    for (i = 0; i < 10; ++i) {
        for (j = i + 1; j < 10; ++j) {
            if(strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    // Print the sorted array
    for (i = 0; i < 10; ++i) {
        if (arr[i][0] != '\0') {
            printf("%s\n", arr[i]);
        }
    }

    return 0;
}
