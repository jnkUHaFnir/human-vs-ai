#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define MAXNAMELEN 1000
#define MAXLINELEN 1000
#define MAXITEMS 100000

char* linesptr[MAXITEMS];

int main(int argc, char ** argv) {
    FILE *infile, *outfile;
    char name[MAXNAMELEN];
    char line[MAXLINELEN];

    int i, items = 0;

    printf("Enter a source filename: ");
    fgets(name, MAXNAMELEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // strip newline
    printf("%s infile \n", name);
    infile = fopen(name, "r");

    while (fgets(line, MAXLINELEN, infile)) {
        int length = strlen(line);
        line[length - 1] = '\0';

        linesptr[items] = malloc(strlen(line) + 1); // Allocate memory for the line
        if (linesptr[items] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        strcpy(linesptr[items], line);
        printf("the input string %d is : %s \n", items, linesptr[items]);
        items++;
    }

    qsort(linesptr, items, sizeof(char*), strcmp);

    printf("Enter a destination filename: ");
    fgets(name, MAXNAMELEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // strip newline
    outfile = fopen(name, "w");

    for (i = 0; i < items; i++) {
        fputs(linesptr[i], outfile);
        free(linesptr[i]); // Free the memory allocated for each line
    }

    fclose(infile);
    fclose(outfile);
}
