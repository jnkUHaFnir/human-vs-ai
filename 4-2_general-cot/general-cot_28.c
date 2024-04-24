#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char *array;
} str1;

void display(str1 *p1) {
    // Allocate memory for the string "Damn"
    p1->array = (char *)malloc(10 * sizeof(char));
    strcpy(p1->array, "Damn");
    
    // Display the content of the array
    printf("%s\n", p1->array);
    
    // Free the allocated memory
    free(p1->array);
}

int main(void) {
    str1 s1;
    
    // Call display function passing address of s1
    display(&s1);

    return 0;
}
