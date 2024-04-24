userToRdrMap = malloc(numOfReducers * sizeof(char*));
for (i = 0; i < numOfReducers; i++) {
    userToRdrMap[i] = malloc(5 * sizeof(char));
}
int findRdrNum(char *userId) {
    if(!userToRdrMap[0]) {
        userToRdrMap[0] = strdup(userId);
        return 0;
    } else {
        int i;
        for(i = 0; i < numOfReducers; i++) {
            if(userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
                return i;
            } else if (userToRdrMap[i] == NULL) {
                userToRdrMap[i] = strdup(userId);
                return i;
            }
        }
    }
    return -1;
}
for (i = 0; i < numOfReducers; i++) {
    if (userToRdrMap[i] != NULL) {
        free(userToRdrMap[i]);
    }
}
free(userToRdrMap);

for (i = 0; i < numOfReducers; i++) {
    userId[i] = NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int numOfReducers;
char **userToRdrMap = NULL;

int findRdrNum(char *userId)
{
    if(!userToRdrMap[0]) {
        userToRdrMap[0] = strdup(userId);
        return 0;
    } else {
        int i;
        for(i = 0; i < numOfReducers; i++) {
            if(userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
                return i;
            } else if (userToRdrMap[i] == NULL) {
                userToRdrMap[i] = strdup(userId);
                return i;
            }
        }
    }
    return -1;
}

int main (int argc, char *argv[])
{
    numOfReducers = atoi(argv[1]);
    int i;
    char userId[numOfReducers][5];
    strcpy(userId[0], "2234");
    strcpy(userId[1], "2222");
    strcpy(userId[2], "3223");
    strcpy(userId[3], "2222");
    int rdrNum;

    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    for (i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL;
    }

    for(i = 0; i < numOfReducers; i++) {
        rdrNum = findRdrNum(userId[i]);
        printf("%d\n", rdrNum);
    }

    for (i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL) {
            free(userToRdrMap[i]);
        }
    }
    free(userToRdrMap);

    for (i = 0; i < numOfReducers; i++) {
        userId[i][0] = '\0';
    }

    return 0;
}
