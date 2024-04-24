#include "stdio.h"
#include "stdlib.h"
#include "string.h" // For strlen function 
#define INIT_SIZE 50

void get_line (char* filename){
    char* text;
    int iter = 1;
    FILE* file = fopen(filename,"r");

    if(file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    text = malloc(sizeof(char) * (INIT_SIZE+1)); // '+1' for the null-terminator.

    while(fgets(text + (iter-1)*INIT_SIZE, INIT_SIZE+1, file) != NULL) // Add '+1' for the null-terminator.
    {
        if(strlen(text) < (iter * INIT_SIZE)) // Check if we read less than what we tried to read
             break;
        iter++;
        text = realloc(text, sizeof(char) * ((iter * INIT_SIZE) + 1)); // Add '+1' for the null-terminator.
    }

    printf("The text was %s\n", text);

    free(text);
    fclose(file);
}

int main(int argc, char *argv[]) {
    get_line(argv[1]);
    return 0;
}
