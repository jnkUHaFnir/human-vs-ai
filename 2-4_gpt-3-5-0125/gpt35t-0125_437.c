#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

int findRdrNum(char *userId){
    if(!userToRdrMap[0]){
        return 0;
    } else{
        int i;
        for(i=0; i<numOfReducers; i++){
            if(strcmp(userToRdrMap[i], userId) == 0)
                return i;
        }
    }
    return -1; // Return -1 if userId is not found
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
    for(i=0; i<numOfReducers; i++){
        userToRdrMap[i] = malloc(5); // Allocate memory for each string (5 is the maximum length of userId)
    }

    for(i=0; i<numOfReducers; i++){
        rdrNum = findRdrNum(userId[i]);
        if(rdrNum == -1){
            // String not found, store it
            strcpy(userToRdrMap[i], userId[i]);
            rdrNum = i;
        }
        printf("Index for %s is %d\n", userId[i], rdrNum);
    }

    // Free allocated memory
    for(i=0; i<numOfReducers; i++){
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
