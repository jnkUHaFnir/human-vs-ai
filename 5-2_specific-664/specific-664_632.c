#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a;
    FILE *p_finput = NULL;
    char *filename = NULL;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    filename = argv[1];

    p_finput = fopen(filename, "r");
    if (p_finput == NULL) {
        printf("Couldn't open %s\n", filename);
        return 1;
    }

    // Read the integer value as ASCII text
    if (fscanf(p_finput, "%d", &a) != 1) {
        printf("Error reading integer from file.\n");
        fclose(p_finput);
        return 1;
    }

    printf("a = %d\n", a);

    fclose(p_finput);
    return 0;
}
