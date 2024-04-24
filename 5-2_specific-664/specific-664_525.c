#include <stdio.h>
#include <string.h>

int main() {
    char scanWord[10][50] = {"hello", "world", "good", "morning", "example", "programming", "language", "security", "question", "answer"};
    char currentWord[10][50] = {"hello", "world", "good", "morning", "example", "programming", "language", "security", "question", "answer"};
    int countX = 0;
    int scoreCurrent = 0;

    while (countX < 10) {
        if (strcmp(scanWord[countX], currentWord[countX]) == 0) {
            scoreCurrent++;
            scoreCurrent++;
        }
        countX++;
    }

    printf("Score: %d\n", scoreCurrent);

    return 0;
}
