#include <stdio.h>
#include <string.h>

int main() {
    char scanWord[10][20]; // Assuming a maximum length of 19 characters for each word
    char currentWord[10][20];
    int countX = 0;
    int scoreCurrent = 0;

    // Initialize scanWord and currentWord arrays with strings
    
    // Assuming countX should be less than 10 as per the provided code
    while (countX < 10) {
        // Comparing the strings using strncmp for a safer comparison
        if (strncmp(scanWord[countX], currentWord[countX], sizeof(scanWord[countX])) == 0) {
            scoreCurrent += 2; // Increment score by 2 if strings match
        }
        countX++;
    }

    printf("Score: %d\n", scoreCurrent);

    return 0;
}
