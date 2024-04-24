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
    FILE * infile, * outfile;
    char name[MAXNAMELEN];
    char line[MAXLINELEN];

    int i, items = 0;

    printf("Enter a source filename: ");
    fgets(name, MAXNAMELEN, stdin);
    name[strlen(name)-1] = '\0'; // strip newline
    printf("%s infile \n", name);
    infile = fopen(name, "r");
    if (infile == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAXLINELEN, infile) && items < MAXITEMS) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }
        /* Allocate memory and copy the string */
        linesptr[items] = malloc(length + 1); // +1 for the null terminator
        if (linesptr[items] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        strcpy(linesptr[items], line);
        printf("The input string %d is: %s \n", items,  linesptr[items]);
        items++;
    }

    // Do not forget to provide a comparison function pointer for qsort rather than strcmp
    qsort(linesptr, items, sizeof(char*), (int (*)(const void*, const void*))strcmp);

    printf("Enter a destination filename: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0'; // strip newline
    outfile = fopen(name, "w");
    if (outfile == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (i = 0; i < items; i++) {
        fputs(linesptr[i], outfile);
    }

    /* Clean up: close files and free memory */
    fclose(infile);
    fclose(outfile);
    for (i = 0; i < items; i++) {
        free(linesptr[i]);
    }
    return 0;
}
