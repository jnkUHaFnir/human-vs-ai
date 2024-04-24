#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

int findRdrNum(char *userId) {
    if (!userToRdrMap) {
        return 0;
    } else {
        for (int i = 0; i < numOfReducers; i++) {
            if (userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    userToRdrMap = malloc(numOfReducers * sizeof(char*));

    char *userId[] = {"2234", "2222", "3223", "2222"};
    int rdrNum;

    for (int i = 0; i < numOfReducers; i++) {
        rdrNum = findRdrNum(userId[i]);
        if (rdrNum == -1) {
            // If userId not found, store it in the first empty slot
            for (int j = 0; j < numOfReducers; j++) {
                if (userToRdrMap[j] == NULL) {
                    userToRdrMap[j] = malloc(strlen(userId[i]) + 1);
                    strcpy(userToRdrMap[j], userId[i]);
                    rdrNum = j;
                    break;
                }
            }
        }
        printf("UserId: %s, RdrNum: %d\n", userId[i], rdrNum);
    }

    // Free allocated memory
    for (int i = 0; i < numOfReducers; i++) {
        if (userToRdrMap[i] != NULL) {
            free(userToRdrMap[i]);
        }
    }
    free(userToRdrMap);

    return 0;
}
