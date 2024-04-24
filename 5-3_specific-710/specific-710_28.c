#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char* array;
} str1;

void display(str1* p1) {
    printf("%s", p1->array);
}

int main(void) {
    str1 s1;
    s1.array = (char*)malloc(5 * sizeof(char)); // Allocate memory for "Damn" along with the null terminator
    strcpy(s1.array, "Damn");
    
    // Call the display function
    display(&s1);

    // Free the allocated memory
    free(s1.array);

    return 0;
}
