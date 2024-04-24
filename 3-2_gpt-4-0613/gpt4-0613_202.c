#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    char a[128] = {0};
    char b[128] = {0};

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *key = strtok(buffer, "=");
        char *value = strtok(NULL, "=");

        if (key != NULL && value != NULL) {
            if (strcmp(key, "a") == 0) {
                strncpy(a, value, sizeof(a) - 1);
            } else if (strcmp(key, "b") == 0) {
                strncpy(b, value, sizeof(b) - 1);
            }
        }
    }
    fclose(fp);

    printf("a=%s, b=%s\n", a, b);
    return 0;
}
a=10
, b=5
