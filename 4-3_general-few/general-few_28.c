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
    s1.array = (char *)malloc(10 * sizeof(char));
    strcpy(s1.array, "Damn");
    
    display(&s1);

    free(s1.array); // Free the memory allocated for the string

    return 0;
}
