#define MAX_ENEMIES 100
Enemy* enemies[MAX_ENEMIES];
int numEnemies = 0;

void RemoveEnemy(int index) {
    if (index >= 0 && index < numEnemies) {
        free(enemies[index]); // Free the memory allocated for the enemy
        for (int i = index; i < numEnemies - 1; i++) {
            enemies[i] = enemies[i + 1]; // Shift the array to fill the gap
        }
        numEnemies--;
    }
}

void AddEnemy(Enemy* newEnemy) {
    if (numEnemies < MAX_ENEMIES) {
        enemies[numEnemies] = newEnemy;
        numEnemies++;
    }
}
