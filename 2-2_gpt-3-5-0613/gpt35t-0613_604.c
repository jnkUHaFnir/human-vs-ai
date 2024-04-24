#include <stdio.h>
#include <string.h>

// Function to replace all occurrences of a substring with an alternate string
char* replaceSubstring(const char* string, const char* find, const char* replace) {
    // Calculate lengths of input strings
    size_t stringLen = strlen(string);
    size_t findLen = strlen(find);
    size_t replaceLen = strlen(replace);

    // Count the number of occurrences of the substring
    int count = 0;
    const char* substr = string;
    while ((substr = strstr(substr, find)) != NULL) {
        count++;
        substr += findLen;
    }

    // Calculate the length of the final string after replacement
    size_t finalLen = stringLen + (replaceLen - findLen) * count + 1;

    // Allocate memory for the final string
    char* finalString = (char*)malloc(finalLen * sizeof(char));
    if (finalString == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    // Perform the replacement
    char* substrPos = strstr(string, find);
    char* finalPos = finalString;
    const char* stringPos = string;

    while (substrPos != NULL) {
        // Copy the portion before the substring
        strncpy(finalPos, stringPos, substrPos - stringPos);
        finalPos += (substrPos - stringPos);

        // Copy the replacement string
        strncpy(finalPos, replace, replaceLen);
        finalPos += replaceLen;

        // Move the original string position
        stringPos = substrPos + findLen;

        // Find the next occurrence of the substring
        substrPos = strstr(stringPos, find);
    }

    // Copy the remaining portion of the original string
    strncpy(finalPos, stringPos, stringLen - (stringPos - string) + 1);

    return finalString;
}

int main() {
    const char* string = "Hello, hello, hello, world!";
    const char* find = "hello";
    const char* replace = "hi";

    char* replacedString = replaceSubstring(string, find, replace);
    if (replacedString != NULL) {
        printf("Original string: %s\n", string);
        printf("Replaced string: %s\n", replacedString);
        free(replacedString);
    }

    return 0;
}
