#include <stdio.h>
#include <stdlib.h>

struct Wizard {
    char name[50];
    int maxHealth;
    int attackMin, attackRange;
    int curHealth, winCount;
};

int saveWiz(struct Wizard * wiz) {
    // Open the file for writing
    FILE * fp = fopen("champion.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1; // Indicating error
    }

    // Allocate memory for the buffer
    char * buff = malloc(100);
    if (buff == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(fp);
        return 1; // Indicating error
    }

    // Use sprintf to format the string with the wizard's stats
    sprintf(buff, "Name: %s\nMax Health: %d\nAttack Min: %d\nAttack Range: %d\nCurrent Health: %d\nWin Count: %d\n",
        wiz->name,
        wiz->maxHealth,
        wiz->attackMin,
        wiz->attackRange,
        wiz->curHealth,
        wiz->winCount);

    // Write the buffer to the file
    fputs(buff, fp);

    // Clean up resources
    fclose(fp);
    free(buff);

    return 0; // Indicating success
}

// Example usage:
int main() {
    struct Wizard gandalf = {
        .name = "Gandalf",
        .maxHealth = 100,
        .attackMin = 15,
        .attackRange = 20,
        .curHealth = 100,
        .winCount = 10
    };

    // Save the Wizard's stats to a file
    saveWiz(&gandalf);

    return 0;
}
