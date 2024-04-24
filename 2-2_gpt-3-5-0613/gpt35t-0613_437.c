#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findRdrNum(char **userToRdrMap, int numOfReducers, char *userId) {
  for (int i = 0; i < numOfReducers; i++) {
    if (userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./program numOfReducers\n");
    return 1;
  }

  int numOfReducers = atoi(argv[1]);

  char **userToRdrMap = malloc(numOfReducers * sizeof(char *));
  for (int i = 0; i < numOfReducers; i++) {
    userToRdrMap[i] = NULL;
  }

  char *userId[] = {"2234", "2222", "3223", "2222"};
  int rdrNum;

  for (int i = 0; i < numOfReducers; i++) {
    rdrNum = findRdrNum(userToRdrMap, numOfReducers, userId[i]);
    if (rdrNum == -1) {
      for (int j = 0; j < numOfReducers; j++) {
        if (userToRdrMap[j] == NULL) {
          userToRdrMap[j] = strdup(userId[i]);
          break;
        }
      }
      rdrNum = findRdrNum(userToRdrMap, numOfReducers, userId[i]);  // Get the index again after storing the string
    }
    printf("%d\n", rdrNum);
  }

  // Free the memory for each string in userToRdrMap
  for (int i = 0; i < numOfReducers; i++) {
    free(userToRdrMap[i]);
  }

  // Free the memory for userToRdrMap
  free(userToRdrMap);

  return 0;
}
