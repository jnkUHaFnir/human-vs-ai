#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_last_three_chars(char* mystr) {
    char* tmp = malloc(strlen(mystr) - 2); // Allocate memory for the modified string
    if(tmp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strncpy(tmp, mystr, strlen(mystr) - 3); // Copy all characters except the last three

    return tmp;
}

int main() {
    char filename[] = "example.txt";
    char* modified = remove_last_three_chars(filename);

    printf("Original filename: %s\n", filename);
    printf("Modified filename: %s\n", modified);

    free(modified); // Free the dynamically allocated memory

    return 0;
}
