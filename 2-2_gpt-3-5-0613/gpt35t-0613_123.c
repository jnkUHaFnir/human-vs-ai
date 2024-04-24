#include<stdio.h>
#include<stdlib.h>

struct Wizard{
 char name[50];
 int maxHealth;
 int attackMin, attackRange;
 int curHealth, winCount;
};

int saveWiz(struct Wizard *wiz) {
  FILE *fp = fopen("champion.txt", "w");
  char *buff = malloc(100);

  sprintf(buff, "Name: %s\n", wiz->name); // Saving the name
  sprintf(buff + strlen(buff), "Max Health: %d\n", wiz->maxHealth); // Saving maxHealth
  sprintf(buff + strlen(buff), "Attack Min: %d\n", wiz->attackMin); // Saving attackMin
  sprintf(buff + strlen(buff), "Attack Range: %d\n", wiz->attackRange); // Saving attackRange
  sprintf(buff + strlen(buff), "Current Health: %d\n", wiz->curHealth); // Saving curHealth
  sprintf(buff + strlen(buff), "Win Count: %d\n", wiz->winCount); // Saving winCount

  fputs(buff, fp);
  fclose(fp);
  free(buff);

  return 0;
}

int main() {
  struct Wizard myWizard = {
    "Harry Potter",
    100,
    10, 20,
    75, 5
  };

  saveWiz(&myWizard);

  return 0;
}
