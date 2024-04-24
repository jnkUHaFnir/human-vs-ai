#include <stdio.h>
#include <string.h>

// Function to remove newline characters from a string
void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char scanWord[10][100];
    char currentWord[10][100];
    int countX = 0;
    int scoreCurrent = 0;

    // Assuming you have scanned the words into scanWord and currentWord arrays

    while (countX < 10) {
        // Remove newline characters from the strings before comparing
        removeNewline(scanWord[countX]);
        removeNewline(currentWord[countX]);

        // Compare the strings
        if (strcmp(scanWord[countX], currentWord[countX]) == 0) {
            scoreCurrent += 2;
        }
        countX++;
    }

    printf("Final Score: %d\n", scoreCurrent);

    return 0;
}
