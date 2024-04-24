#include <stdio.h>
#include <stdlib.h>

void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    char *buffer = malloc(15 * sizeof(char));
    fgets(buffer, 15, fp);
    
    sscanf(buffer, "%d", pX); // Use sscanf instead of scanf
    
    free(buffer);
    fclose(fp);
}
