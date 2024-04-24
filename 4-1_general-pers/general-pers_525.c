#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char scanWord[10][MAX_LENGTH] = {"word1", "word2", "word3", "word4", "word5", "word6", "word7", "word8", "word9", "word10"};
    char currentWord[10][MAX_LENGTH] = {"word1", "word2", "word3", "word4", "word5", "word6", "word7", "word8", "word9", "word10"};
    
    int scoreCurrent = 0;
    int countX = 0;
    
    while(countX < 10) {
        if (strncmp(scanWord[countX], currentWord[countX], MAX_LENGTH) == 0) {
            scoreCurrent += 2; // Increase score if strings are equal
        }
        countX++;
    }
    
    printf("Final score: %d\n", scoreCurrent);
    
    return 0;
}
