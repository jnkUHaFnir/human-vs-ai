#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 100 // Maximum number of enemies

typedef struct Enemy {
    // Define enemy properties here
    int health;
} Enemy;

Enemy* enemies[MAX_ENEMIES];
int numEnemies = 0;

void addEnemy() {
    if (numEnemies < MAX_ENEMIES) {
        Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
        if (newEnemy == NULL) {
            printf("Memory allocation failed for new enemy.\n");
            return;
        }

        // Initialize the new enemy
        newEnemy->health = 100;

        // Add the new enemy to the array
        enemies[numEnemies] = newEnemy;
        numEnemies++;
        printf("New enemy added.\n");
    } else {
        printf("Cannot add more enemies. Maximum limit reached.\n");
    }
}

void removeEnemy(int index) {
    if (index >= 0 && index < numEnemies) {
        free(enemies[index]);
        for (int i = index; i < numEnemies - 1; i++) {
            enemies[i] = enemies[i + 1];
        }
        numEnemies--;
        printf("Enemy removed.\n");
    } else {
        printf("Invalid enemy index.\n");
    }
}

int main() {
    addEnemy();
    addEnemy();
    
    removeEnemy(1);

    // Clean up memory
    for (int i = 0; i < numEnemies; i++) {
        free(enemies[i]);
    }

    return 0;
}
