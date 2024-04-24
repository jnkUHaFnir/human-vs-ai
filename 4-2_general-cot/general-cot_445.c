#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanData(char* data) {
    int i, j = 0;

    for (i = 0; data[i] != '\0'; i++) {
        if (isalnum(data[i]) || isspace(data[i])) {
            data[j] = data[i];
            j++;
        }
    }
    data[j] = '\0';
}

int main() {
    char data[] = "This is an example 123 !! data with extra line breaks.\n\n\n";

    // Call cleanData function to filter out unwanted characters
    cleanData(data);

    printf("Filtered data: %s\n", data);

    return 0;
}
