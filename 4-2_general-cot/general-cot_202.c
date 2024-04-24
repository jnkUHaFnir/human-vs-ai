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
        if (sscanf(buffer, "%127s %d", zimu, &zahla) == 2) {
            if (strcmp(zimu, "a=") == 0) {
                printf("zimu is: %s\n", zimu);
            }
        }
        if (sscanf(buffer, "%127s %d", zimu, &zahlb) == 2) {
            if (strcmp(zimu, "b=") == 0) {
                printf("zimu is: %s\n", zimu);
            }
        }
    }

    printf("a=%s, b=%s\n", zahla, zahlb);
    
    fclose(fp);
    return 0;
}
