#include <stdio.h>
#include <string.h>

int main() {
    char str[] = {"This is the first sentence, And this is the second"};
    int length = strlen(str);

    // Traverse string from end
    int i;
    for (i = length - 1; i >= 0; i--) {
        if (str[i] == ' ' || str[i] == ',') { // Added condition for comma as well

            // putting the NULL character at the position of space characters for next iteration.
            str[i] = '\0';

            // Start from next character
            printf("%s ", &(str[i]) + 1);
        }
    }

    // printing the last word
    printf("%s", str);

    return 0;
}
