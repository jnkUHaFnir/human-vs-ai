#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ConvertToString(char **subject, const char *insert) {
    size_t len = strlen(*subject) + strlen(insert) + 1;
    char *temp = malloc(len);
    if (temp == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    snprintf(temp, len, "%s%s", *subject, insert);
    free(*subject); // Free previous memory
    *subject = temp;
}

int main() {
    char *String4H1 = strdup("*FV");  // Using strdup to allocate memory and initialize
    char *String4H3 = strdup("*RV");  // Using strdup to allocate memory and initialize
    char data1[4], data2[4];

    snprintf(data1, sizeof(data1), "%03d", 200);
    snprintf(data2, sizeof(data2), "%03d", 200);

    ConvertToString(&String4H1, data1);   // *FV200
    ConvertToString(&String4H3, data2);   // *RV200

    ConvertToString(&String4H1, "#");     // *FV200#
    ConvertToString(&String4H3, "#");     // *RV200#

    printf("String4H1: %s\n", String4H1);
    printf("String4H3: %s\n", String4H3);

    free(String4H1);  // Free allocated memory
    free(String4H3);  // Free allocated memory

    return 0;
}

void ConvertToString(char **subject, const char *insert) {
    size_t len = strlen(*subject) + strlen(insert) + 1;
    char *temp = malloc(len);
    if (temp == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    snprintf(temp, len, "%s%s", *subject, insert);
    free(*subject); // Free previous memory
    *subject = temp;
}
