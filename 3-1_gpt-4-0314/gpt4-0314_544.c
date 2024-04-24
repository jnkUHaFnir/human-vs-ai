#include <stdio.h>
#include <stdlib.h>

void bar(char *fileName, int *pX);
void foo();

int main() {
    foo();
    return 0;
}

void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
    printf("Value of x: %d\n", x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char buffer[15];
    fgets(buffer, 15, fp);
    sscanf(buffer, "%d", pX); // Use sscanf() instead of scanf()
    fclose(fp);
}
