#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    int a, b;
    char zimu[128];

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, "%s", zimu);
        if (strcmp(zimu, "a") == 0) {
            sscanf(buffer, "a=%d", &a);
        }
        if (strcmp(zimu, "b") == 0) {
            sscanf(buffer, "b=%d", &b);
        }
    }
    printf("a=%d, b=%d\n", a, b);
    fclose(fp);
    return 0;
}
