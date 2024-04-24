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
        sscanf(buffer, " %s", zimu); // Read the first word (which is 'a' or 'b')

        if (strcmp(zimu, "a") == 0) {
            sscanf(buffer, "%*[^=]=%d", &zahla); // Read integer after '='
        }
        if (strcmp(zimu, "b") == 0) {
            sscanf(buffer, "%*[^=]=%d", &zahlb); // Read integer after '='
        }
    }

    printf("a=%s, b=%s\n", zahla, zahlb);
    fclose(fp);

    return 0;
}
