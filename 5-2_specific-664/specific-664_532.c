#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    scanf("%s", str); // Input the string

    for (int i = 0; i < strlen(str); i++) {
        int found = 0;
        for (int j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) {
                printf("The first repeated character is: %c\n", str[i]);
                found = 1;
                break; // Break out of the inner loop once a repeated character is found
            }
        }
        if(found) {
            break; // Break out of the outer loop once the first repeated character is found
        }
    }

    return 0;
}
