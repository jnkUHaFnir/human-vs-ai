#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a;
    FILE *p_finput = NULL;
    char *filename = NULL;

    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
  
    p_finput = fopen(filename, "r"); // Open file in text mode
    if (p_finput == NULL) {
        printf("couldn't open %s\n", filename);
        return 1;
    }

    if (fscanf(p_finput, "%d", &a) != 1) { // Read integer from file
        printf("Error reading integer from file.\n");
        return 1;
    }

    printf("a = %d\n", a);

    fclose(p_finput);
    return 0;
}
