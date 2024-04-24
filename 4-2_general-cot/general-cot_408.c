#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sanitizeString(char *input) {
    char *result = (char *)malloc(strlen(input) * 2 + 1); // Allocate memory for the result string

    char charLookup[][3] = { "ab","\xe0a", "ss", "\xe5a", "\xc5A", "\xffy", "XX","" }; // Using hex codes for extended ASCII characters

    int resultIndex = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        int j = 0;
        int found = 0;

        while (charLookup[j][0] != '\0') {
            if (input[i] == charLookup[j][0]) {
                found = 1;
                strcat(result, &charLookup[j][1]); // Append the replacement character from lookup
                resultIndex += 2;
                break;
            }
            j++;
        }

        if (!found) {
            result[resultIndex++] = input[i];
        }
    }

    result[resultIndex] = '\0'; // Add null terminator to the end of the string
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char* sanitized = sanitizeString(argv[1]);
    printf("Sanitized string: %s\n", sanitized);

    free(sanitized); // Free dynamically allocated memory

    return 0;
}
