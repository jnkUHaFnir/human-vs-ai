#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAMELEN 1000
#define MAXLINELEN 1000
#define MAXITEMS 100000

char* linesptr[MAXITEMS];

int main(int argc, char ** argv) {
    FILE * infile, * outfile;
    char name[MAXNAMELEN];
    char line[MAXLINELEN];

    int i, items = 0;

    printf("Enter a source filename: ");
    fgets(name, MAXNAMELEN, stdin);
    name[strlen(name)-1] = '\0'; // strip newline
    
    infile = fopen(name, "r");
    if (infile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    while (fgets(line, MAXLINELEN, infile)) {
        int length = strlen(line);
        line[length-1] = '\0';

        // Allocate memory for the line
        linesptr[items] = malloc(length * sizeof(char));
        if (linesptr[items] == NULL) {
            printf("Error allocating memory.\n");
            return 1;
        }

        // Copy the line into the allocated memory
        strcpy(linesptr[items], line);
        
        printf("The input string %d is: %s\n", items, linesptr[items]);
        items++;
    }
    
    fclose(infile);
    
    qsort(linesptr, items, sizeof(char*), strcmp);
    
    printf("Enter a destination filename: ");
    fgets(name, MAXNAMELEN, stdin);
    name[strlen(name)-1] = '\0'; // strip newline
    outfile = fopen(name, "w");
    if (outfile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    for (i=0; i<items; i++) {
        fputs(linesptr[i], outfile);
        free(linesptr[i]); // Free the allocated memory for each line
    }
    
    fclose(outfile);
    
    return 0;
}
