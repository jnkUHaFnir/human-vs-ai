#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100

void* emalloc(size_t size) {
    void* result = malloc(size);
    if (result == NULL) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main(void) {
    char* username[MAX_WORDS];
    size_t len;
    size_t n = 0;

    /* Read words into array */
    for (size_t i = 0; i < MAX_WORDS && scanf("%ms", &username[i]) == 1; i++) {
        n++;
    }

    /* Print out array */
    for (size_t p = 0; p < n; p++) {
        printf("%s\n", username[p]);
        free(username[p]);
    }

    return 0;
}
for (size_t i = 0; i < MAX_WORDS && scanf("%ms", &username[i]) == 1; i++) {
    username[i] = emalloc(strlen(username[i]) * sizeof(char));
    n++;
}
