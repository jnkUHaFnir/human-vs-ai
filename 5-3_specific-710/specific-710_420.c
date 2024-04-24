#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_string(char *string){
    int len = strlen(string);
    int i, j = 0;

    char* temp = malloc((len + 1) * sizeof(char)); // Allocate memory for temp
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for(i = len - 1; i >= 0; i--){
        temp[j] = string[i];
        j++;
    }
    temp[j] = '\0'; // Add null terminator at the end

    return temp;
}

int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char* result = flip_string(argv[1]);
    printf("Reversed string: %s\n", result);

    free(result); // Free allocated memory
    printf("This is the end of the program\n");

    return 0;
}
