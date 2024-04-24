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

        if (strncmp(zimu, "a=", 2) == 0) {
            sscanf(buffer, "%*[^=]=%127[0-9]", zahla);
        }
        if (strncmp(zimu, "b=", 2) == 0) {
            sscanf(buffer, "%*[^=]=%127[0-9]", zahlb);
        }
    }

    printf("a=%s, b=%s\n", zahla, zahlb);
    
    fclose(fp);
    return 0;
}
