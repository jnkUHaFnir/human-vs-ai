#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 100

// Enemy structure
typedef struct {
    int id;
    // Add other enemy attributes here
} Enemy;

// Array of pointers to enemies
Enemy* enemies[MAX_ENEMIES] = { NULL };

// Number of enemies currently in the array
int numEnemies = 0;

// Function to remove a killed enemy from the array
void removeEnemy(Enemy* enemy) {
    for (int i = 0; i < numEnemies; ++i) {
        if (enemies[i] == enemy) {
            free(enemies[i]); // Free memory of the killed enemy
            // Shift remaining enemies to fill the gap
            for (int j = i; j < numEnemies - 1; ++j) {
                enemies[j] = enemies[j + 1];
            }
            enemies[numEnemies - 1] = NULL; // Clear the last pointer
            numEnemies--;
            break;
        }
    }
}

// Function to add a new enemy to the array
void addEnemy(int id) {
    if (numEnemies < MAX_ENEMIES) {
        Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
        newEnemy->id = id;
        enemies[numEnemies] = newEnemy;
        numEnemies++;
    } else {
        printf("Cannot add more enemies. Array is full.\n");
    }
}

int main() {
    // Add a new enemy with ID 1
    addEnemy(1);

    // Simulate killing an enemy with ID 1
    if (enemies[0]->id == 1) {
        removeEnemy(enemies[0]);
    }

    // Add a new enemy with ID 2
    addEnemy(2);

    // Clean up remaining enemies
    for (int i = 0; i < numEnemies; ++i) {
        free(enemies[i]);
    }

    return 0;
}
