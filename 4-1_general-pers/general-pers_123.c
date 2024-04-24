#include <stdio.h>
#include <stdlib.h>

struct Wizard {
    char name[50];
    int maxHealth;
    int attackMin, attackRange;
    int curHealth, winCount;
};

int saveWiz(struct Wizard *wiz) {
    if (wiz == NULL) {
        return -1; // Ensure pointer is valid
    }

    FILE *fp = fopen("champion.txt", "w");
    if (fp == NULL) {
        return -1; // Check if file was opened successfully
    }

    fprintf(fp, "Name: %s\n", wiz->name);
    fprintf(fp, "Max Health: %d\n", wiz->maxHealth);
    fprintf(fp, "Attack Min: %d\n", wiz->attackMin);
    fprintf(fp, "Attack Range: %d\n", wiz->attackRange);
    fprintf(fp, "Current Health: %d\n", wiz->curHealth);
    fprintf(fp, "Win Count: %d\n", wiz->winCount);

    fclose(fp);
    return 0;
}
