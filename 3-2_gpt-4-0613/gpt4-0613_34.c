#include <stdio.h>

/* The lengths 50 are unsafe as it assumes the users will never enter a longer file name */
int main() {
      FILE *fin;
      FILE *fout;
      char fInName[256];
      char fOutName[256];

      printf("Please type input file, and output file please type legibly\n");

      fgets(fInName, 256, stdin);
      fgets(fOutName, 256, stdin);

      if (fInName[0] == '\n' && fOutName[0] == '\n') {
          printf("No files specified.\n");
      }
      else if (fInName[0] != '\n' && fOutName[0] == '\n') {
        printf("Output file not specified.\n");
      }
      else {
          fin = fopen(fInName, "r");
          fout = fopen(fOutName, "w");

          if (fin == NULL) {
              printf("Error: Cannot open input file %s.", fInName);
          }
          
          if (fout == NULL) {
              printf("Error: Cannot open output file %s.", fOutName);
          }

          /* Add code to handle file streams here */

          fclose(fin);
          fclose(fout);
      }
      return 0;
}
