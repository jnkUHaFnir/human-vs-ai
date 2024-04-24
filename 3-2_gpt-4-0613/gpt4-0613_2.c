#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char *array;
} str1;

void display(str1 *p1) {
    printf("%s", p1->array);
}

int main(void) {
    str1 s1;
    s1.array = (char *)malloc(10 * sizeof(char)); // Allocate memory
    strcpy(s1.array, "Damn"); // Copying into allocated memory
    display(&s1); // Call display function
    free(s1.array); // Don't forget to free the allocated memory
    return 0;
}
