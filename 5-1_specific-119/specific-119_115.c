#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 100

// Define an enemy structure
typedef struct {
    int health;
    // Add other properties as needed
} Enemy;

// Global array of enemy pointers
Enemy* enemies[MAX_ENEMIES];
int numEnemies = 0;

// Function to remove an enemy by index
void removeEnemy(int index) {
    if(index < 0 || index >= numEnemies) {
        printf("Invalid enemy index\n");
        return;
    }

    // Free the memory for the enemy
    free(enemies[index]);

    // Shift the rest of the enemies
    for(int i = index; i < numEnemies - 1; i++) {
        enemies[i] = enemies[i + 1];
    }

    numEnemies--;
}

// Function to create a new enemy
void createEnemy(int health) {
    if(numEnemies < MAX_ENEMIES) {
        Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
        newEnemy->health = health;
        // Initialize other properties as needed

        enemies[numEnemies] = newEnemy;
        numEnemies++;
    } else {
        printf("Cannot create more enemies, limit reached\n");
    }
}

int main() {
    // Create some enemies
    createEnemy(100);
    createEnemy(150);
    createEnemy(200);

    // Remove an enemy (e.g., when they are killed)
    removeEnemy(1);

    // Print remaining enemies' health
    for(int i = 0; i < numEnemies; i++) {
        printf("Enemy %d - Health: %d\n", i, enemies[i]->health);
    }

    // Free memory for remaining enemies
    for(int i = 0; i < numEnemies; i++) {
        free(enemies[i]);
    }

    return 0;
}
