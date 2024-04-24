#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0, j;
    char* string[100];
    char line[100];
    FILE* file;
    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    while (fgets(line, sizeof line, file) != NULL) {
        string[i] = malloc(strlen(line) + 1); // Allocate memory for the line
        strcpy(string[i], line); // Copy the line into the allocated memory
        printf("%d %s", i, string[i]);
        i++;
    }
    
    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Don't forget to free the allocated memory
    }
    
    fclose(file);
    return 0;
}
0 rec
1 cent
2 ece
3 ce
4 recent
5 nt
string[0] rec
string[1] cent
string[2] ece
string[3] ce
string[4] recent
string[5] nt
