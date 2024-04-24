#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int numOfReducers;
char** userToRdrMap;

int findRdrNum(char *userId){
  for(int i=0; i < numOfReducers; i++){
    if(userToRdrMap[i] != NULL && strcmp(userToRdrMap[i], userId) == 0){
        return i;
    }
  }

  for(int i=0; i < numOfReducers; i++){
    if(userToRdrMap[i] == NULL){
      userToRdrMap[i] = malloc(strlen(userId) + 1);
      strcpy(userToRdrMap[i], userId);
      return i;
    }
  }
  // if we didn't find a spot to insert, return -1
  return -1;
}

int main (int argc, char *argv[])
{
  numOfReducers = atoi(argv[1]);

  char *userId[numOfReducers];
  userId[0] = "2234";
  userId[1] = "2222";
  userId[2] = "3223";
  userId[3] = "2222";
  int rdrNum;

  userToRdrMap = malloc(numOfReducers * sizeof(char*));
  memset(userToRdrMap, 0, numOfReducers * sizeof(char*));

  for(int i=0; i<numOfReducers; i++){
    rdrNum = findRdrNum(userId[i]);
    printf("Index: %d\n", rdrNum);
  }
  return 0;
}
