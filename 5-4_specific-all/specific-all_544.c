#include <stdio.h>
#include <stdlib.h>

void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
    printf("Value of x after reading from file: %d\n", x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp != NULL) {
        char buffer[15];
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "%d", pX);
        fclose(fp);
    } else {
        printf("Error opening file.\n");
    }
}

int main() {
    foo();
    return 0;
}
