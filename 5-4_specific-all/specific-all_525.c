#include <stdio.h>
#include <string.h>

int main() {
    char scanWord[10][50];  // Assuming max length of each word is 50 characters
    char currentWord[10][50];
    int countX = 0;
    int scoreCurrent = 0;

    // Code to input strings into scanWord and currentWord arrays before the comparison loop

    // Assuming scanWord and currentWord are properly initialized before comparison
    while (countX < 10) {
        if (strcmp(scanWord[countX], currentWord[countX]) == 0) {
            scoreCurrent += 2; // Incrementing the score by 2 if strings are equal
        }
        countX++;
    }

    printf("Final current score: %d\n", scoreCurrent);

    return 0;
}
