#include <stdio.h>
#include <stdlib.h>

void bar(char *fileName, int *pX);

void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char buffer[15];
    fgets(buffer, 15, fp);
    
    if(sscanf(buffer, "%d", pX) != 1) {
        printf("Error reading integer from file.\n");
        return;
    }

    fclose(fp);
}

int main() {
    foo();
    return 0;
}
