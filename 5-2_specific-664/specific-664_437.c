#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

int findRdrNum(char *userId) {
    if(!userToRdrMap[0]) {
        return 0;
    } else{
        int i;
        for(i = 0; i < numOfReducers; i++){
            if(strcmp(userToRdrMap[i], userId) == 0)
                return i;
        }
    }
    return -1; // Return -1 if userId is not found
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    
    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    for (int i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL; // Initialize each entry to NULL
    }

    char *userId[] = {"2234", "2222", "3223", "2222"};
    for (int i = 0; i < numOfReducers; i++) {
        int rdrNum = findRdrNum(userId[i]);
        
        if (rdrNum == -1) {
            // Store userId if not found
            for (int j = 0; j < numOfReducers; j++) {
                if (!userToRdrMap[j]) {
                    userToRdrMap[j] = strdup(userId[i]); // Allocate memory and copy data
                    printf("Stored userId %s at index %d\n", userId[i], j);
                    break;
                }
            }
        } else {
            printf("Found userId %s at index %d\n", userId[i], rdrNum);
        }
    }

    // Free memory
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i]) {
            free(userToRdrMap[i]);
        }
    }
    free(userToRdrMap);

    return 0;
}
