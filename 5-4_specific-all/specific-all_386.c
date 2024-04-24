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
    "REDK"
};

char *removechar(char str[], int ch) {
    char *cpos = str;
    while ((cpos = strchr(cpos, ch))) {
        strcpy(cpos, cpos + 1);
    }
    return str;
}

int main(int argc, char **argv) {
    char *reds[max];
    int i;

    if (argc != 2) {
        printf("[ERR] Usage: %s <input_file>\n", argv[0]);
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
    }

    for (i = 0; i < max; i++) {
        printf("%s", reds[i]);
    }

    // Remove spaces
    for (i = 0; i < max; i++) {
        removechar(reds[i], ' ');
    }

    for (i = 0; i < max; i++) {
        printf("%s", reds[i]);
    }

    int success = 1;
    size_t size = sizeof(stringcard) / sizeof(stringcard[0]);
    size_t size2 = sizeof(reds) / sizeof(reds[0]);

    if (size == size2) {
        for (int i = 0; i < size; i++) {
            if (strcmp(stringcard[i], reds[i]) != 0) {
                success = 0;
                printf("No match: %s\n", reds[i]);
                break;
            }
        }
    } else {
        printf("Size mismatch between arrays.\n");
    }

    fclose(file);

    return 0;
}
