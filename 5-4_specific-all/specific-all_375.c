#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    name[strcspn(name, "\n")] = 0; // remove newline character

    infile = fopen(name, "r");
    if (infile == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return 1;
    }

    while (fgets(line, MAXLINELEN, infile)) {
        line[strcspn(line, "\n")] = 0; // remove newline character

        linesptr[items] = strdup(line); // store a copy of the line
        printf("the input string %d is: %s\n", items, linesptr[items]);
        items++;
    }

    qsort(linesptr, items, sizeof(char*), strcmp);

    printf("Enter a destination filename: ");
    fgets(name, MAXNAMELEN, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline character

    outfile = fopen(name, "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }

    for (i = 0; i < items; i++) {
        fputs(linesptr[i], outfile);
        fputc('\n', outfile); // add newline after each line
    }

    // Free allocated memory for each line
    for (i = 0; i < items; i++) {
        free(linesptr[i]);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}
