#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_empty(const char *s) {
    while (*s != '\0') {
        if (!isspace((unsigned char)*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *pdata;
    char buffer[1000];
    char *token, *del = ",";
    int value1;
    double value2;

    pdata = fopen("file.data", "r");

    if (pdata == NULL) {
        printf("Unable to open file \n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), pdata) != NULL) {
        // Check if the line is empty or contains only whitespace
        if (is_empty(buffer)) {
            continue; // Skip empty lines
        }

        token = strtok(buffer, del);
        value1 = atoi(strtok(NULL, del));
        value2 = atof(strtok(NULL, del));

        printf("%s is %.3lf\n", token, value1 + value2);
    }

    fclose(pdata);

    return 0;
}
