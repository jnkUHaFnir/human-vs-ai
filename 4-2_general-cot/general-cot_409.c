#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char output[500][MAX_LENGTH]; // Assuming each string has a maximum length of MAX_LENGTH
    int j, k;

    for (j = 1; j < 500; j++) {
        char doubled[MAX_LENGTH * 2]; // Allocate memory to hold the doubled string
        strcpy(doubled, output[j]);
        strcat(doubled, output[j]); // Concatenate the string to itself

        int occurrence_count = 0;
        for (k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                occurrence_count++;
            }
        }

        if (occurrence_count == 1) {
            strcpy(output[j], doubled); // Save the doubled string if it occurs only once
        } else if (occurrence_count > 1) {
            output[j][0] = '\0'; // Remove the string if it occurs more than once
        }
    }

    // Printing the updated strings
    for (int i = 1; i < 500; i++) {
        if (output[i][0] != '\0') {
            printf("%s\n", output[i]);
        }
    }

    return 0;
}
