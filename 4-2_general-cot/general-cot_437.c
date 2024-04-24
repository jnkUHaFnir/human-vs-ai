#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10 // Maximum length for each string

int numOfReducers;
char** userToRdrMap = NULL;

char* findRdrNum(char* userId) {
    int i;
    for (i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
            return userToRdrMap[i]; // Return the found pointer
        }
    }
    // If not found, find an empty slot to store the userId
    for (i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] == NULL) {
            userToRdrMap[i] = malloc(MAX_LEN * sizeof(char));
            strcpy(userToRdrMap[i], userId);
            return userToRdrMap[i]; // Return the stored pointer
        }
    }
    return NULL; // Not found and no empty slot available
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    int i;

    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    for (i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL;
    }

    char* userId[] = {"2234", "2222", "3223", "2222"};
    for (i = 0; i < numOfReducers; i++) {
        char* foundUserId = findRdrNum(userId[i]);
        printf("User %s found/stored at index: %d\n", userId[i], foundUserId ? (foundUserId - userToRdrMap[0]) / MAX_LEN : -1);
    }

    // Free allocated memory for userToRdrMap
    for (i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
