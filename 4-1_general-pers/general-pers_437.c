#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

int findRdrNum(char *userId) {
    if (userToRdrMap == NULL) {
        return -1; // Array not initialized
    }

    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
            return i; // User ID found at index i
        }
    }

    // User ID not found
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] == NULL) {
            userToRdrMap[i] = strdup(userId); // Store user ID at index i
            return i;
        }
    }

    // Array full, unable to store more user IDs
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    userToRdrMap = (char**)malloc(numOfReducers * sizeof(char*));
    for (int i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL; // Initialize each element to NULL
    }

    char *userId[] = {"2234", "2222", "3223", "2222"};
    
    for (int i = 0; i < numOfReducers; i++) {
        int rdrNum = findRdrNum(userId[i]);
        if (rdrNum < 0) {
            printf("Unable to store user ID: %s\n", userId[i]);
        } else {
            printf("User ID: %s, Index: %d\n", userId[i], rdrNum);
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
