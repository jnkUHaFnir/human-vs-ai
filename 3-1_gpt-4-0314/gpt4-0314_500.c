#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input1[] = "Hello World";
    char input2[] = "I am an AI.";
    
    size_t len1 = strlen(input1);
    size_t len2 = strlen(input2);
    
    printf("<");
    for (size_t i = 0; i < len1; ++i) {
        putchar(toupper(input1[i]));
    }
    printf("> <");
    
    for (size_t i = 0; i < len2; ++i) {
        putchar(toupper(input2[i]));
    }
    printf(">\n");
    
    return 0;
}
