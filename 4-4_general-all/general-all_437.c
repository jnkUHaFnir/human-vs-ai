#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap;

int findRdrNum(char *userId) {
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
            return i; // User ID found, return the index
        }
    }
    
    // User ID not found, search for an empty slot to store the user ID
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] == NULL) {
            userToRdrMap[i] = strdup(userId); // Store the user ID in an empty slot
            return i;
        }
    }
    
    return -1; // Array full, couldn't store the user ID
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num_of_reducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    if (numOfReducers <= 0) {
        printf("Invalid number of reducers.\n");
        return 1;
    }

    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    if (userToRdrMap == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Initialize userToRdrMap
    for (int i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL;
    }

    // Array of user IDs
    char *userId[] = {"2234", "2222", "3223", "2222"};
    
    for (int i = 0; i < numOfReducers; i++) {
        int rdrNum = findRdrNum(userId[i]);
        if (rdrNum == -1) {
            printf("Failed to store user ID: %s. Array full.\n", userId[i]);
        } else {
            printf("User ID: %s, Index: %d\n", userId[i], rdrNum);
        }
    }

    // Free memory for userToRdrMap
    for (int i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
