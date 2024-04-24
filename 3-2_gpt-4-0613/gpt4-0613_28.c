#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct
typedef struct myStruct { 
    char *array; 
} str1;

// function to print the data in the struct
void display(str1 *p1) {
    printf("%s\n", p1->array);
}

int main(void) {
    str1 s1;

    s1.array = (char *) malloc(10 * sizeof(char)); // allocate memory
    strcpy(s1.array, "Damn");

    // call display function
    display(&s1);
    
    free(s1.array); // always free allocated memory when you're done with it

    return 0;
}
