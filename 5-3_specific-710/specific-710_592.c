#include <stdio.h>
#include <string.h>

int main() {
    char *s1;
    char *st7;
    char str1[] = "s__bye;k__hi;s__apple";
    char arr[10][10], temp[10];
    int i, j, k;

    s1 = strtok(str1, ";");
    k = 0;
    while (s1 != NULL) {
        st7 = strstr(s1, "s__");
        if (st7 != NULL) {
            strcpy(arr[k], st7);
            k++;
        }
        s1 = strtok(NULL, ";");
    }

    // Sort the strings in lexicographical order
    for (i = 0; i < k - 1; i++) {
        for (j = i + 1; j < k; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    // Print the sorted strings
    for (i = 0; i < k; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
