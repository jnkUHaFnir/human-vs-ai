#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    int i, j;
    int found = 0;

    for (i = 0; i < strlen(str) && !found; i++) {
        for (j = i + 1; j < strlen(str) && !found; j++) {
            if (str[i] == str[j]) { // Compare
                printf("The first repeated character is: %c\n", str[i]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No repeated character found in the string.\n");
    }

    return 0;
}
