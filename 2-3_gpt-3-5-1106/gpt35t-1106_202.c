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
        if (sscanf(buffer, "a=%s", zahla) == 1) {
            printf("a is: %s\n", zahla);
        }
        if (sscanf(buffer, "b=%s", zahlb) == 1) {
            printf("b is: %s\n", zahlb);
        }
    }
    fclose(fp);
    return 0;
}
a=10
b=5
a is: 10
b is: 5
