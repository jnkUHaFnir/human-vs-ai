#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i=0,j;
    char* string[100];
    char line[100];
    FILE *file; 
    file = fopen("patt", "r"); 
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
    while(fgets(line, sizeof line, file)!=NULL) {
        printf("%d %s",i, line);
        string[i]=strdup(line); // this allocates memory and copies contents of 'line'
        i++;
    }
    fclose(file);
    for (j=0 ; j<i ; j++) {
        printf("string[%d] %s",j, string[j]);
        free(string[j]); // free the memory you've allocated
    }
    return 0;
}
