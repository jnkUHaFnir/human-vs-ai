#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap;

int findRdrNum(char *userId){
    for(int i=0; i<numOfReducers; i++){
        if(userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0){
            return i;
        }
    }

    for(int i=0; i<numOfReducers; i++){
        if(userToRdrMap[i] == NULL){
            userToRdrMap[i] = malloc(strlen(userId) + 1);
            strcpy(userToRdrMap[i], userId);
            return i;
        }
    }

    return -1; // We couldn't find a slot to store the userId
}

int main (int argc, char *argv[])
{
    numOfReducers = atoi(argv[1]);
    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    for(int i=0; i<numOfReducers; i++){
        userToRdrMap[i] = NULL; // Initialize each slot to NULL
    }

    char *userId[numOfReducers];
    userId[0] = "2234";
    userId[1] = "2222";
    userId[2] = "3223";
    userId[3] = "2222";
    int rdrNum;

    for(int i=0; i<numOfReducers; i++){
        rdrNum = findRdrNum(userId[i]);
        printf("UserId: %s, RdrNum: %d\n", userId[i], rdrNum);
    }

    // Remember to free the memory you allocated for userToRdrMap
    for(int i=0; i<numOfReducers; i++){
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);
    
    return 0;
}
