#include <stdio.h>
#include <string.h>
#include <ctype.h>

void filterData(char* inputData, char* filteredData) {
    int j = 0;
    for (int i = 0; inputData[i] != '\0'; i++) {
        if (isalnum(inputData[i]) || isspace(inputData[i])) {
            filteredData[j++] = inputData[i];
        }
    }
    filteredData[j] = '\0';
}

int main() {
    // Sample input data with extra line breaks
    char inputData[] = "H3llO\n W0rlD!\n123";

    // Filtered data will contain only letters, numbers, and spaces
    char filteredData[100];
    filterData(inputData, filteredData);

    // Output the filtered data
    printf("Filtered Data: %s\n", filteredData);

    return 0;
}
