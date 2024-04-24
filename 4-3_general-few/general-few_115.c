#include <stdio.h>
#include <stdlib.h>

// Define a structure for an enemy
typedef struct {
    int id;
    // Add more properties as needed
} Enemy;

int main() {
    int maxSize = 10; // Maximum size of the enemy array
    Enemy* enemies = (Enemy*)malloc(maxSize * sizeof(Enemy));
    int numEnemies = 0;

    // Function to add a new enemy
    void addEnemy(int enemyId) {
        if (numEnemies < maxSize) {
            enemies[numEnemies].id = enemyId;
            numEnemies++;
            printf("Added new enemy with ID: %d\n", enemyId);
        } else {
            printf("Cannot add more enemies. Array is full.\n");
        }
    }

    // Function to remove an enemy by ID
    void removeEnemy(int enemyId) {
        for (int i = 0; i < numEnemies; i++) {
            if (enemies[i].id == enemyId) {
                for (int j = i; j < numEnemies - 1; j++) {
                    enemies[j] = enemies[j + 1];
                }
                numEnemies--;
                printf("Removed enemy with ID: %d\n", enemyId);
                return;
            }
        }
        printf("Enemy with ID %d not found.\n", enemyId);
    }

    // Test adding and removing enemies
    addEnemy(1);
    addEnemy(2);
    addEnemy(3);
    removeEnemy(2);
    addEnemy(4);

    // Free memory before exiting
    free(enemies);

    return 0;
}
