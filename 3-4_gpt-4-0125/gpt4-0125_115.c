#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    // Add other attributes here
} Enemy;
// Global variable for this example; consider passing it around as needed.
Enemy **enemies = NULL;
int enemyCount = 0;

void addEnemy(Enemy* newEnemy) {
    enemyCount++;
    enemies = (Enemy**)realloc(enemies, enemyCount * sizeof(Enemy*));
    enemies[enemyCount - 1] = newEnemy;
}

void removeEnemy(int index) {
    if (index < 0 || index >= enemyCount) return; // Out of bounds check

    free(enemies[index]); // Free the memory for the removed enemy

    // Shift remaining enemies to cover the gap
    for (int i = index; i < enemyCount - 1; i++) {
        enemies[i] = enemies[i + 1];
    }

    enemyCount--;
    enemies = (Enemy**)realloc(enemies, enemyCount * sizeof(Enemy*));
}
int main() {
    // Add an enemy
    Enemy *enemy1 = (Enemy*)malloc(sizeof(Enemy));
    enemy1->id = 1;
    addEnemy(enemy1);
    
    // Add another enemy
    Enemy *enemy2 = (Enemy*)malloc(sizeof(Enemy));
    enemy2->id = 2;
    addEnemy(enemy2);

    // Example: remove the first enemy
    removeEnemy(0);

    // Always free remaining enemies and the enemies array itself to avoid memory leaks
    for (int i = 0; i < enemyCount; i++) {
        free(enemies[i]);
    }
    free(enemies);

    return 0;
}
