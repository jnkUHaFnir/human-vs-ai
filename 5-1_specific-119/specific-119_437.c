#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

int findRdrNum(char *userId) {
    if (userToRdrMap == NULL) {
        return -1;
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
    if (argc != 2) {
        printf("Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    char *userId[] = {"2234", "2222", "3223", "2222"};
    int rdrNum;

    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    if (userToRdrMap == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = NULL;
    }

    for (int i = 0; i < numOfReducers; i++) {
        rdrNum = findRdrNum(userId[i]);
        if (rdrNum == -1) {
            // Find an empty slot in userToRdrMap
            for (int j = 0; j < numOfReducers; j++) {
                if (userToRdrMap[j] == NULL) {
                    userToRdrMap[j] = strdup(userId[i]);
                    rdrNum = j;
                    break;
                }
            }
        }
        printf("%d\n", rdrNum);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
