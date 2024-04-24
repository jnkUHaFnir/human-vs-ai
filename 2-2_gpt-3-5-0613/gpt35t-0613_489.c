#include <stdio.h>
#include <stdlib.h>
#include #include <string.h>  // for strcpy()

int main(void) {
    int i = 0, j;
    char* string[100];
    char line[100];
    FILE* file;
    
    file = fopen("patt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    while (fgets(line, sizeof line, file) != NULL) {
        // Remove the newline character at the end of each line
        line[strcspn(line, "\n")] = '\0';
        
        printf("%d %s\n", i, line);
        
        // Dynamically allocate memory for the line and copy it
        string[i] = malloc(strlen(line) + 1);  // +1 for the null terminator
        strcpy(string[i], line);
        
        i++;
    }
    
    for (j = 0; j < i; j++) {
        printf("string[%d] %s\n", j, string[j]);
        free(string[j]);  // Free the dynamically allocated memory
    }
    
    fclose(file);
    return 0;
}
