scanWord[i] = strdup("some_string");
// or
scanWord[i] = (char *) malloc(strlen("some_string") + 1);
strcpy(scanWord[i], "some_string");
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *scanWord[10] = {"cat", "dog", "fish", "bird", "frog", "lion", "tiger", "bear", "shark", "whale"};
    char *currentWord[10] = {"cat", "rat", "fish", "bird", "snake", "lion", "tiger", "wolf", "shark", "dolphin"};

    int scoreCurrent = 0;
    int countX = 0;
    
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
