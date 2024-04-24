#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *ptr = malloc(256);

    if (!ptr) {
        printf("Error, malloc\n");
        exit(1);
    }

    strcpy(ptr, "Michi");

    char *tmpPtr = realloc(ptr, 1024 * 102400000uL); 

    if (tmpPtr) {
        ptr = tmpPtr;
        strcat(ptr, " - Aloha");
    } else {
        printf("Error, realloc\n");

        // Do not free ptr here as realloc failed and ptr still points to valid memory
    }

    printf("PTR = %s\n", ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}
