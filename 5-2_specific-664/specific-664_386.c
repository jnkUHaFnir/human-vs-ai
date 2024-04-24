#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 13
#define stringlength 8

const char *stringcard[] = {
    "REDA",
    "RED2",
    "RED3",
    "RED4",
    "RED5",
    "RED6",
    "RED7",
    "RED8",
    "RED9",
    "RED10",
    "REDJ",
    "REDQ",
    "REDK",
};

char *removechar(char str[], int ch) {
    char *cpos = str;

    while ((cpos = strchr(cpos, ch))) {
        strcpy(cpos, cpos + 1);
    }
    return str;
}

int compareArrays(char *reds[], const char *stringcard[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(stringcard[i], reds[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    char *reds[max];
    int i;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < max; i++) {
        reds[i] = malloc(stringlength);
        fgets(reds[i], stringlength, file);
        removechar(reds[i], ' '); // remove spaces
    }
    
    fclose(file);

    int success = compareArrays(reds, stringcard, max);

    if (success) {
        printf("Input matches the predefined strings.\n");
    } else {
        printf("Input does not match the predefined strings.\n");
    }

    // Free allocated memory
    for (i = 0; i < max; i++) {
        free(reds[i]);
    }

    return 0;
}
