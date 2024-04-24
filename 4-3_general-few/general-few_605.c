#include <stdio.h>
#include <string.h>

int main() {
    char line[100]; // Assuming a maximum line length of 100 characters
    int integers[100]; // Assuming a maximum of 100 integers per line
    int numIntegers = 0;

    // Read lines until EOF
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int i = 0;
        char *token = strtok(line, ":, \n"); // Tokenize based on colon, comma, space, or newline

        while (token != NULL) {
            integers[i++] = atoi(token);
            numIntegers++;
            token = strtok(NULL, ":, \n");

            // Assuming newline indicates end of line
            if (token != NULL && strchr(token, '\n')) {
                // Perform tasks using the integers array
                printf("Integers array for the current line:\n");
                for (int j = 0; j < numIntegers; j++) {
                    printf("%d ", integers[j]);
                }
                printf("\n");

                // Reset the array for the next line
                numIntegers = 0;
                i = 0;
            }
        }
    }

    return 0;
}
