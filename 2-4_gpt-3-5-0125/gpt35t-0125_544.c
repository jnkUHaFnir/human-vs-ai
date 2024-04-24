#include <stdio.h>
#include <stdlib.h>

void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
    printf("Value of x is: %d\n", x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    char *buffer = malloc(15 * sizeof(int));
    fgets(buffer, 15, fp);
    sscanf(buffer, "%d", pX);
    free(buffer);
    fclose(fp);
}

int main() {
    foo();
    return 0;
}
