#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    char zahla[128];
    char zahlb[128];
    char zimu[128];

    fp = fopen("0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return -1;
    }
    
    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, "%s %s", zimu, zahla); // read zimu and zahla from the line
        if (strcmp(zimu, "a=") == 0) {
            // remove the 'a=' from the zahla
            memmove(zahla, zahla+2, strlen(zahla));
            // convert zahla to int
            int a = atoi(zahla);
            printf("a=%d\n", a);
        } else if (strcmp(zimu, "b=") == 0) {
            // remove the 'b=' from the zahlb
            memmove(zahla, zahla+2, strlen(zahla));
            // convert zahlb to int
            int b = atoi(zahla);
            printf("b=%d\n", b);
        }
    }

    fclose(fp);
    return 0;
}
