#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char *array;
} str1;

void display(str1 *p1) {
    // Allocate memory and copy the content from the struct member before printing
    char *array = (char *)malloc((strlen(p1->array) + 1) * sizeof(char));
    strcpy(array, p1->array);
    printf("%s\n", array);
    free(array); // Free the allocated memory
}

int main(void) {
    str1 s1;
    s1.array = "Damn"; // Assign the string correctly
    display(&s1); // Call the display function with a pointer to s1
    return 0;
}
