#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int i, j;

    // Input the string
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        int repeated = 0; // Flag to track if character is repeated

        for (j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) {
                // First repeated character found
                printf("%c\n", str[i]);
                repeated = 1;
                break;
            }
        }

        if (repeated) {
            break; // Break outer loop if repeated character found
        }
    }

    return 0;
}
