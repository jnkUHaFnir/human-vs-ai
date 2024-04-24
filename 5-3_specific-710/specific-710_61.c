#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
    char *name;
    char *surname;
    char *address;
    char *number;
} Person;

char *getString(void);

int main(void) {
    Person *rub = NULL, *ttmp = NULL;
    int idx = 0, i, j, k;
    char c;
    char *tmp = NULL;
    do {
        // Your main logic here
    } while (c != '0');
    return 0;
}

char *getString(void) {
    char *stringa = NULL;
    int i = 0;
    int size = 1; // Initial size
    stringa = malloc(size * sizeof(char));
    if (stringa == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    char c;
    while ((c = getchar()) != '\n') {
        stringa[i++] = c;
        if (i >= size) {
            size *= 2; // Double the size
            stringa = realloc(stringa, size * sizeof(char));
            if (stringa == NULL) {
                printf("Memory reallocation failed.\n");
                exit(1);
            }
        }
    }
    stringa[i] = '\0';
    return stringa;
}
