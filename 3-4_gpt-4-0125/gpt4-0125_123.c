#include <stdio.h>
#include <stdlib.h>

struct Wizard{
 char name[50];
 int maxHealth;
 int attackMin, attackRange;
 int curHealth, winCount;
};

int saveWiz(struct Wizard *wiz)
{
  FILE *fp = fopen("champion.txt", "w");
  if (fp == NULL) {
      printf("Error opening file\n");
      return -1; // Indicate failure
  }

  // Allocate a buffer large enough for the data
  char * buff = malloc(200); // Increased size to accommodate larger data
  if (buff == NULL) {
      printf("Memory allocation failed\n");
      fclose(fp);
      return -1; // Indicate failure
  }

  // Assume all integers will consume less than 10 chars, adjust if necessary.
  // Write all details in one go
  sprintf(buff, "Name: %s\nMax Health: %d\nMinimum Attack: %d\nAttack Range: %d\nCurrent Health: %d\nWin Count: %d\n",
          wiz->name, wiz->maxHealth, wiz->attackMin, wiz->attackRange, wiz->curHealth, wiz->winCount);

  fputs(buff, fp); // Write the buffer to file
  fclose(fp);      // Close the file
  free(buff);      // Free the allocated memory
  
  return 0; // Success
}

// Example usage
int main() {
    struct Wizard exampleWiz = {
        "Gandalf",
        100, // maxHealth
        10, // attackMin
        20, // attackRange
        80, // curHealth
        5  // winCount
    };

    saveWiz(&exampleWiz);

    return 0;
}
