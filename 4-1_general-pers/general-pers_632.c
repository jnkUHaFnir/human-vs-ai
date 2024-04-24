#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a;
    FILE *p_finput = NULL;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    p_finput = fopen(argv[1], "r");
    if (p_finput == NULL) {
        printf("Couldn't open %s\n", argv[1]);
        return 1;
    }

    if (fscanf(p_finput, "%d", &a) == 1) {
        printf("a = %d\n", a);
    } else {
        printf("Error reading integer from file.\n");
    }

    fclose(p_finput);
    return 0;
}
