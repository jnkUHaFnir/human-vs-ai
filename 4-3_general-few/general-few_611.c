#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0, j;
    char string[100][100]; // 2D array to store each line
    char line[100];
    FILE *file; 
    file = fopen("patt", "r"); 
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        strcpy(string[i], line); // Copy line into string[i]
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
    }

    fclose(file);
    return 0;
}
