#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    int zahla = 0;
    int zahlb = 0;
    char zimu[128];

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, "%s", zimu); // Read the first word (e.g., 'a' or 'b')
        if (strcmp(zimu, "a") == 0) {
            sscanf(buffer, "a=%d", &zahla); // Read the integer value following 'a='
        }
        if (strcmp(zimu, "b") == 0) {
            sscanf(buffer, "b=%d", &zahlb); // Read the integer value following 'b='
        }
    }
    printf("a=%d, b=%d\n", zahla, zahlb);

    fclose(fp);
    return 0;
}
