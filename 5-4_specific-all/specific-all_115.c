#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 100

// Structure representing an enemy
typedef struct Enemy {
    int id;
} Enemy;

int main() {
    // Array to hold enemy pointers
    Enemy* enemies[MAX_ENEMIES];
    int numEnemies = 0;

    // Assume we have some enemies in the beginning
    for (int i = 0; i < 3; i++) {
        Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
        newEnemy->id = i;
        enemies[numEnemies] = newEnemy;
        numEnemies++;
    }

    // Enemy with id 1 is killed
    int killedEnemyId = 1;
    for (int i = 0; i < numEnemies; i++) {
        if (enemies[i]->id == killedEnemyId) {
            free(enemies[i]);
            for (int j = i; j < numEnemies - 1; j++) {
                enemies[j] = enemies[j + 1];
            }
            numEnemies--;
            break;
        }
    }

    // Create a new enemy
    Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
    newEnemy->id = 3;
    enemies[numEnemies] = newEnemy;
    numEnemies++;

    // Clean up - free memory for all enemies
    for (int i = 0; i < numEnemies; i++) {
        free(enemies[i]);
    }

    return 0;
}
