#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char *array;
} str1;

void display(str1 *p1) {
    p1->array = (char *)malloc(10 * sizeof(char));
    strcpy(p1->array, "Damn");
    printf("%s", p1->array);
    free(p1->array); // Free memory allocated in display
}

int main(void) {
    str1 s1;
    display(&s1); // Call display function passing the address of the struct
    return 0;
}
