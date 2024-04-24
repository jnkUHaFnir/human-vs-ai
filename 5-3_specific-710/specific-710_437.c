#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap = NULL;

int findRdrNum(char *userId) {
    if (!userToRdrMap[0][0]) {
        return 0;
    } else {
        int i;
        for (i = 0; i < numOfReducers; i++) {
            if (strcmp(userToRdrMap[i], userId) == 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <numOfReducers>\n", argv[0]);
        return 1;
    }

    numOfReducers = atoi(argv[1]);
    int i;
    char *userId[] = {"2234", "2222", "3223", "2222"};
    int rdrNum;

    userToRdrMap = malloc(numOfReducers * sizeof(char*));
    for (i = 0; i < numOfReducers; i++) {
        userToRdrMap[i] = malloc(strlen(userId[i]) + 1);
    }

    for (i = 0; i < numOfReducers; i++) {
        rdrNum = findRdrNum(userId[i]);
        if (rdrNum == -1) {
            for (int j = 0; j < numOfReducers; j++) {
                if (!userToRdrMap[j][0]) {
                    strcpy(userToRdrMap[j], userId[i]);
                    printf("%s stored at index: %d\n", userId[i], j);
                    break;
                }
            }
        } else {
            printf("%s found at index: %d\n", userId[i], rdrNum);
        }
    }

    // Free allocated memory
    for (i = 0; i < numOfReducers; i++) {
        free(userToRdrMap[i]);
    }
    free(userToRdrMap);

    return 0;
}
