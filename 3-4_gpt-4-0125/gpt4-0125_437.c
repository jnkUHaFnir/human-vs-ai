#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap;

int findRdrNum(char *userId){
    for(int i = 0; i < numOfReducers; i++){
        if(userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
            return i;
        }
    }
    // Not found, so store and return new index
    for(int i = 0; i < numOfReducers; i++){
        if(userToRdrMap[i] == NULL) { // Found a spot to store it
            userToRdrMap[i] = strdup(userId); // Allocate and copy string
            return i;
        }
    }
    return -1; // Should never get here if numOfReducers is correctly sized
}

int main (int argc, char *argv[])
{
    if(argc < 2) {
        printf("Usage: %s numOfReducers\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);

    // Allocate and initialize memory for userToRdrMap
    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    for (int i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL; // Initialize every pointer to NULL
    }

    // Sample userIds
    char *userId[] = {"2234", "2222", "3223", "2222"};
    int numOfUsers = sizeof(userId) / sizeof(userId[0]);

    for(int i = 0; i < numOfUsers; i++){
        int rdrNum = findRdrNum(userId[i]);
        printf("UserId %s is at index %d\n", userId[i], rdrNum);
    }

    // Cleanup
    for(int i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
