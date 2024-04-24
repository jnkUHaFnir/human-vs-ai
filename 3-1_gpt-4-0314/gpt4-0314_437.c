#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int numOfReducers;
char **userToRdrMap;

int findRdrNum(char *userId){
    for(int i=0; i<numOfReducers; i++){
        if(userToRdrMap[i] && strcmp(userToRdrMap[i], userId) == 0) {
            return i;
        }
    }
    return -1;
}

int main (int argc, char *argv[])
{
    numOfReducers = atoi(argv[1]);
    int i;
    char *userId[numOfReducers];
    userId[0] = "2234";
    userId[1] = "2222";
    userId[2] = "3223";
    userId[3] = "2222";
    int rdrNum;

    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    memset(userToRdrMap, 0, numOfReducers * sizeof(char*)); // Initialize the array with NULL pointers

    for(i=0; i<numOfReducers; i++){
        rdrNum = findRdrNum(userId[i]);
        if (rdrNum == -1) {
            userToRdrMap[numOfReducers] = malloc(strlen(userId[i]) + 1);
            strcpy(userToRdrMap[numOfReducers], userId[i]);
            rdrNum = numOfReducers;
            numOfReducers++;
            userToRdrMap = realloc(userToRdrMap, numOfReducers * sizeof(char*));
            userToRdrMap[numOfReducers] = NULL;
        }
        printf("User %s assigned to reducer %d\n", userId[i], rdrNum);
    }

    // Free allocated memory
    for (i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i]) {
            free(userToRdrMap[i]);
        }
    }
    free(userToRdrMap);

    return 0;
}
