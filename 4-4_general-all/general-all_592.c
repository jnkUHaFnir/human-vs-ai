#include <stdio.h>
#include <string.h>

int main() {
    char *str1 = "s__dog;s__cat;s__apple;s__zebra"; // Example input string
    char *s1, *st7;
    int i, j;
    char arr[10][10], temp[10]; // Updated sizes to prevent buffer overflow

    s1 = strtok(str1, ";");
    int count = 0;

    while (s1 != NULL) {
        st7 = strstr(s1, "s__");
        if (st7 != NULL) {
            strcpy(arr[count], st7); // Copy the substring starting from "s__" to the array
            count++;
        }
        s1 = strtok(NULL, ";");
    }

    // Sorting the strings in lexicographical order
    for(i = 0; i < count - 1; i++) {
        for(j = i + 1; j < count; j++) {
            if(strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    // Printing the strings in lexicographical order
    for(i = 0; i < count; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
