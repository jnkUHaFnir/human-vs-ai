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
    s1.array = (char *)malloc(sizeof(char) * 10); // Allocate memory for the string array
    if (s1.array == NULL) {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        return 1; // Exit the program if memory allocation fails
    }
    
    strcpy(s1.array, "Damn");
    
    display(&s1); // Call the display function to print the output
    
    free(s1.array); // Free the allocated memory
    
    return 0;
}
