#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINELEN 1000
#define MAXITEMS 100000

char linesptr[MAXITEMS][MAXLINELEN]; // Change from char* to fixed size char array

int main() {

    FILE *infile, *outfile;
    char name[MAXLINELEN];
    char line[MAXLINELEN];
    int i, items = 0;

    printf("Enter a source filename: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';
    printf("%s infile \n", name);
    
    infile = fopen(name, "r");
    if (infile == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), infile)) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0'; // Remove newline character
        }

        // Copy the line into the array
        strcpy(linesptr[items], line);
        printf("the input string %d is : %s \n", items, linesptr[items]);
        items++;
    }

    qsort(linesptr, items, sizeof(line), strcmp);

    printf("Enter a destination filename: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    outfile = fopen(name, "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }

    for (i = 0; i < items; i++) {
        fputs(linesptr[i], outfile);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
