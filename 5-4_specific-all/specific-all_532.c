#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        for (int j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) {
                printf("The first repeated character is: %c\n", str[i]);
                return 0; // end the program after printing the first repeated character
            }
        }
    }

    printf("No repeated characters found.\n");
    return 0;
}
