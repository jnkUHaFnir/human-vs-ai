#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char *array;
} str1;

void display(str1 *p1) {
    printf("%s\n", p1->array);
}

int main(void) {
    str1 s1;
    
    // Allocate memory for s1.array
    s1.array = (char *)malloc(10 * sizeof(char));
    if (s1.array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Copy the string "Damn" into s1.array
    strcpy(s1.array, "Damn");

    // Call the display function to print the string
    display(&s1);

    // Free the allocated memory
    free(s1.array);

    return 0;
}
