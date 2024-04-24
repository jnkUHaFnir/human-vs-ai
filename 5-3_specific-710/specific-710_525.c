#include <stdio.h>
#include <string.h>

int main() {
    char scanWord[10][20]; // Assuming 10 strings with max length 20
    char currentWord[10][20]; // Assuming 10 strings with max length 20
    int countX = 0;
    int scoreCurrent = 0;

    // Initialize scanWord and currentWord arrays with sample values
    strcpy(scanWord[0], "hello");
    strcpy(scanWord[1], "world");
    strcpy(scanWord[2], "good");
    strcpy(scanWord[3], "morning");
    strcpy(scanWord[4], "example");

    strcpy(currentWord[0], "hello");
    strcpy(currentWord[1], "world");
    strcpy(currentWord[2], "good");
    strcpy(currentWord[3], "morning");
    strcpy(currentWord[4], "example");

    while (countX < 5) { // Assuming only first 5 elements are populated
        if (strcmp(scanWord[countX], currentWord[countX]) == 0) {
            scoreCurrent += 2; // Increase score by 2 if strings are equal
        }
        countX++;
    }

    printf("Final Score: %d\n", scoreCurrent);

    return 0;
}
