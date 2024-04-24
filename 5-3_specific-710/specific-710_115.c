#include <stdio.h>
#include <stdlib.h>

#define MAX_ENEMIES 100

typedef struct Enemy {
    int id;
    // Add other enemy properties here
} Enemy;

Enemy* enemies[MAX_ENEMIES];
int numEnemies = 0;

void removeEnemy(int index) {
    // Free memory for the enemy to be removed
    free(enemies[index]);
    
    // Shift the rest of the array to fill the gap
    for (int i = index; i < numEnemies - 1; i++) {
        enemies[i] = enemies[i + 1];
    }
    
    numEnemies--;
}

void createEnemy(int id) {
    if (numEnemies < MAX_ENEMIES) {
        Enemy* newEnemy = (Enemy*)malloc(sizeof(Enemy));
        newEnemy->id = id;
        
        // Initialize other properties of the new enemy
        
        enemies[numEnemies] = newEnemy;
        numEnemies++;
    } else {
        printf("Max enemies reached, cannot create more.\n");
    }
}

int main() {
    // Create some initial enemies
    createEnemy(1);
    createEnemy(2);
    
    // Remove an enemy (e.g., when killed)
    removeEnemy(0);
    
    // Create a new enemy
    createEnemy(3);
    
    // Print out the remaining enemies
    for (int i = 0; i < numEnemies; i++) {
        printf("Enemy ID: %d\n", enemies[i]->id);
    }
    
    // Free memory for remaining enemies
    for (int i = 0; i < numEnemies; i++) {
        free(enemies[i]);
    }
    
    return 0;
}
