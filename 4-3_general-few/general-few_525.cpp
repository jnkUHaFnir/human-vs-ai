#include <stdio.h>
#include <string.h>

int main() {
    char scanWord[10][20] = {"hello", "world", "example", "string", "test", "programming", "language", "computer", "science", "engineering"};
    char currentWord[10][20] = {"hello", "world", "example", "string", "test", "programming", "language", "computer", "science", "engineering"};
    int countX = 0;
    int scoreCurrent = 0;

    while (countX < 10) {
        if (strcmp(scanWord[countX], currentWord[countX]) == 0) {
            scoreCurrent += 2; // Increment scoreCurrent by 2 if strings are equal
        }
        countX++;
    }

    printf("Final score: %d\n", scoreCurrent);

    return 0;
}
