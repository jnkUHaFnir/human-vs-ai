#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AppendToString(char **dest, const char *src) {
    char *tmp = malloc(strlen(*dest) + strlen(src) + 1);
    strcpy(tmp, *dest);
    strcat(tmp, src);
    free(*dest);
    *dest = tmp;
}

int main() {
    char String4H1[10] = "*FV";
    char String4H3[10] = "*RV";
    char String4H2[10] = "#";

    char data1[10];
    char data2[10];

    int num1 = GetWord("@FrontVIB@", 0);
    int num2 = GetWord("@RearVIB@", 0);

    snprintf(data1, 10, "%s%d", "*FV", num1);
    snprintf(data2, 10, "%s%d", "*RV", num2);

    AppendToString(&String4H1, data1);
    AppendToString(&String4H3, data2);

    AppendToString(&String4H1, String4H2);
    AppendToString(&String4H3, String4H2);

    // Display String4H1 And String4H3
    printf("Final String4H1: %s\n", String4H1);
    printf("Final String4H3: %s\n", String4H3);

    // Free allocated memory
    free(String4H1);
    free(String4H3);

    return 0;
}
