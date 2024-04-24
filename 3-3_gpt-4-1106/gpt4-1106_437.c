#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

// Function to find or add the userId to the userToRdrMap
int findRdrNum(char *userId){
    // Check if there is already an existing user
    for(int i = 0; i < numOfReducers; i++) {
        if(userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0)
            return i; // Return index if user is found
    }
    
    // If user is not found, store it
    for(int i = 0; i < numOfReducers; i++) {
        if(userToRdrMap[i] == NULL) {
            userToRdrMap[i] = strdup(userId); // Allocate and copy the userId
            return i; // Return the new index
        }
    }
    
    // If we're here, there's no room to store a new user
    return -1; // Indicate an error or full array
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <numberOfReducers>\n", argv[0]);
        return 1;
    }
    
    numOfReducers = atoi(argv[1]);
    if(numOfReducers <= 0) {
        fprintf(stderr, "Invalid number of reducers.\n");
        return 1;
    }
    
    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    // Initialize to NULL to represent empty slots
    for (int i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL;
    }
    
    // Example userIds
    char *userId[] = {
        "2234", "2222", "3223", "2222"
    };
    int numUserIds = sizeof(userId) / sizeof(userId[0]);
    
    for(int i = 0; i < numUserIds; i++) {
        int rdrNum = findRdrNum(userId[i]);
        if (rdrNum >= 0) {
            printf("User '%s' is mapped to reducer #%d\n", userId[i], rdrNum);
        } else {
            printf("Error: No room to store new user '%s'\n", userId[i]);
        }
    }
    
    // Cleanup allocated memory
    for (int i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);
    
    return 0;
}
