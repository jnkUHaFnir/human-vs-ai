#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 100

// Enemy structure
typedef struct {
    int id;
    // Add more enemy attributes here
} Enemy;

int main() {
    Enemy* enemies[MAX_ENEMIES] = { NULL };
    int numEnemies = 0;

    // Create a new enemy
    Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
    if (newEnemy == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }
    newEnemy->id = 1; // Set an example id
    enemies[numEnemies] = newEnemy;
    numEnemies++;

    // Now let's remove an enemy (e.g., by id)
    int enemyIdToRemove = 1;
    for (int i = 0; i < numEnemies; i++) {
        if (enemies[i]->id == enemyIdToRemove) {
            free(enemies[i]);
            // Shift remaining enemies in the array
            for (int j = i; j < numEnemies - 1; j++) {
                enemies[j] = enemies[j + 1];
            }
            numEnemies--;
            break; // Exit loop after removing the enemy
        }
    }

    // Clean up: free memory for remaining enemies
    for (int i = 0; i < numEnemies; i++) {
        free(enemies[i]);
    }

    return 0;
}
