#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure
typedef struct myStruct {
    char *array; // Pointer to a string
} str1;

// Function to display the contents of the structure
void display(str1 *p1) {
    printf("%s\n", p1->array);
}

int main(void) {
    str1 s1; 

    // Allocate memory for the string and ensure it's not NULL
    s1.array = (char *)malloc(10 * sizeof(char)); // Allocate memory for string
    if (s1.array == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Copy "Damn" into s1.array
    strcpy(s1.array, "Damn");

    // Call display to print the contents of s1.array
    display(&s1);

    // Free dynamically allocated memory
    free(s1.array);

    return 0;
}
