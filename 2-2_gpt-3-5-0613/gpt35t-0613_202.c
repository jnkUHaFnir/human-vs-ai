#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* trim(char* str) {
    char* end;

    // Trim leading space
    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return str;
    }

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null terminate after the last non-space character
    end[1] = '\0';

    return str;
}

int main() {
    FILE* fp;
    char buffer[1024];
    char zahla[128];
    char zahlb[128];
    char zimu[128];

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return -1;
    }

    while (fgets(buffer, 1024, fp) != NULL) {
        sscanf(buffer, "%s", zimu);
        printf("zimu is: %s\n", zimu);

        if (strcmp(zimu, "a") == 0) {
            sscanf(buffer, "%*[^=]=%s", zahla);
            strcpy(zahla, trim(zahla));
        }

        if (strcmp(zimu, "b") == 0) {
            sscanf(buffer, "%*[^=]=%s", zahlb);
            strcpy(zahlb, trim(zahlb));
        }
    }

    fclose(fp);

    printf("a=%s, b=%s\n", zahla, zahlb);

    return 0;
}
