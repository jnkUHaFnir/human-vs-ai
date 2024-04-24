#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    char zahla[128];
    char zahlb[128];
    char zimu[128];

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, "%s", zimu);
        printf("zimu is: %s\n", zimu);

        if (strcmp(zimu, "a=") == 0) {
            sscanf(buffer, "a=%s", zahla);
        }
        if (strcmp(zimu, "b=") == 0) {
            sscanf(buffer, "b=%s", zahlb);
        }
    }
    int a = atoi(zahla);
    int b = atoi(zahlb);
    printf("a=%d, b=%d\n", a, b);

    fclose(fp);
    return 0;
}
