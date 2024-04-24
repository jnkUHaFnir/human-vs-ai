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
 printf("%s infile \n",name);
 infile = fopen(name, "r");
 while (fgets(line, MAXLINELEN, infile)) {
    int length = strlen(line);
    if (length > 0) {
        line[length-1] = '\0'; // strip newline
        linesptr[items] = (char *) malloc(length * sizeof(char));
        strcpy(linesptr[items], line);
        printf("the input string %d is : %s \n",items,  linesptr[items]);
        items++;
    }
 }

 qsort(linesptr, items, MAXLINELEN, strcmp); 
 printf("Enter a destination filename: ");
 fgets(name, sizeof(name), stdin);
 name[strlen(name)-1] = '\0'; // strip newline
 outfile = fopen(name, "w");
 for (i=0; i<items; i++) {
    fputs(linesptr[i], outfile);
 }

 fclose(infile);
 fclose(outfile);

 // Free allocated memory
 for (i = 0; i < items; ++i) {
     free(linesptr[i]);
 }
}
