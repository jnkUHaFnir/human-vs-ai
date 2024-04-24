#include <stdio.h>
#include <string.h>

// Function to compare strings for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *s1, *st7, *str1 = "s__bye;k__abc;s__def";
    int i = 0;
    char arr[10][10], temp[10][10];

    s1 = strtok(str1, ";");
    while (s1 != NULL) {
        st7 = strstr(s1, "s__");
        if (st7 != NULL) {
            strcpy(arr[i], st7);
            i++;
        }
        s1 = strtok(NULL, ";");
    }

    // Sorting the strings in lexicographical order
    qsort(arr, i, sizeof(arr[0]), compareStrings);

    // Printing the sorted strings
    for (int j = 0; j < i; j++) {
        printf("%s\n", arr[j]);
    }

    return 0;
}
