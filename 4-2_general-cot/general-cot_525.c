#include <stdio.h>
#include <string.h>

int main() {
    char *scanWord[10] = {"hello", "world", "foo", "bar", "test", "example", "apple", "orange", "cat", "dog"};
    char *currentWord[10] = {"hello", "planets", "foo", "bar", "exam", "example", "banana", "orange", "rabbit", "dog"};

    int countX = 0, scoreCurrent = 0;

    while(countX < 10) {
        if(strcmp(scanWord[countX], currentWord[countX]) == 0) {
            scoreCurrent++;
            scoreCurrent++;
        }
        countX++;
    }

    printf("Score for currentWord: %d\n", scoreCurrent);

    return 0;
}
