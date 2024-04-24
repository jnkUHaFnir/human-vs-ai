#include <stdio.h>
#include <stdlib.h>
char* read_input() {
    char* input = malloc(sizeof(char));
    int size = 1;
    int index = 0;
    int ch;
    
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(-1);
    }
    
    while ((ch = getchar()) != '\n') {
        input[index++] = ch;
        
        input = realloc(input, (++size) * sizeof(char));
        if (input == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(-1);
        }
    }
    
    input[index] = '\0';
    return input;
}
int main() {
    printf("Enter employee address: ");
    char* address = read_input();
    
    printf("Employee address: %s\n", address);
    
    free(address);
    return 0;
}
