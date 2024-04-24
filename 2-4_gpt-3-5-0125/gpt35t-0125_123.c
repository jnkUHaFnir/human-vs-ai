#include <stdio.h>
#include <stdlib.h>

struct Wizard {
    char name[50];
    int maxHealth;
    int attackMin, attackRange;
    int curHealth, winCount;
};

int saveWiz(struct Wizard *wiz) {
    FILE *fp = fopen("champion.txt", "w");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1; // return error code
    }
    
    char buff[100];
    sprintf(buff, "Name: %s\nMax Health: %d\nAttack Min: %d\nAttack Range: %d\nCurrent Health: %d\nWin Count: %d\n", 
            wiz->name, wiz->maxHealth, wiz->attackMin, wiz->attackRange, wiz->curHealth, wiz->winCount);
    
    fputs(buff, fp);
    fclose(fp);
    
    return 0; // return success
}

int main() {
    struct Wizard sampleWizard = {"Gandalf", 100, 10, 20, 100, 5};
    saveWiz(&sampleWizard);
    return 0;
}
