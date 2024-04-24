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
        sscanf(buffer, "%s %s", zimu, zahla); // Read two strings separated by a space
        if (strcmp(zimu, "a=") == 0) {
            strncpy(zahla, zahla+2, sizeof(zahla)); // Remove "a=" from the value
        }
        else if (strcmp(zimu, "b=") == 0) {
            strncpy(zahlb, zahla+2, sizeof(zahlb)); // Remove "b=" from the value
        }
    }
    printf("a=%s, b=%s\n", zahla, zahlb);
    
    fclose(fp); // Close the file when done
    return 0;
}
