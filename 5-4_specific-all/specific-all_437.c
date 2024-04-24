#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap;

int findRdrNum(char *userId) {
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
            return i; // String found, return index
        }
    }

    // String not found, store in the array and return the index
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] == NULL) {
            userToRdrMap[i] = strdup(userId); // Store the string in the array
            return i;
        }
    }

    return -1; // Array is full, handle this case accordingly
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    userToRdrMap = malloc(numOfReducers * sizeof(char*));

    char *userId[] = {"2234", "2222", "3223", "2222"};
    int rdrNum;

    for (int i = 0; i < numOfReducers; i++) {
        rdrNum = findRdrNum(userId[i]);
        printf("Index for %s: %d\n", userId[i], rdrNum);
    }

    // Don't forget to free the memory allocated for userToRdrMap
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL) {
            free(userToRdrMap[i]);
        }
    }
    free(userToRdrMap);

    return 0;
}
