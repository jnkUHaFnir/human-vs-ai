#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    char zahla[128] = {0};
    char zahlb[128] = {0};
    char zimu[128];

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, " %1[a-zA-Z]=%s", zimu, zahla);
 
        if (strcmp(zimu, "a") == 0) {
            strncpy(zahla, zahla, sizeof(zahla) - 1);
        } else if (strcmp(zimu, "b") == 0) {
            strncpy(zahlb, zahla, sizeof(zahlb) - 1);
        }
    }
    fclose(fp);

    printf("a=%s, b=%s\n", zahla, zahlb);

    return 0;
}
