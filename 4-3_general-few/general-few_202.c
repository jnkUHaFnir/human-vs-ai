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

        if (zimu[0] == 'a') {
            sscanf(buffer, "%*[^=]=%s", zahla);
        }
        if (zimu[0] == 'b') {
            sscanf(buffer, "%*[^=]=%s", zahlb);
        }
    }
    printf("a=%s, b=%s\n", zahla, zahlb);

    fclose(fp); // Don't forget to close the file
    return 0;
}
