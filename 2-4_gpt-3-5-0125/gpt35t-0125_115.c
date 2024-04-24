// Define a maximum number of enemies
#define MAX_ENEMIES 10

// Declare an array of enemy pointers
ENTITY* enemyList[MAX_ENEMIES];

// Initialize the enemy list
void initEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemyList[i] = NULL;
    }
}

// Add a new enemy to the list
void addEnemy(ENTITY* enemy) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemyList[i] == NULL) {
            enemyList[i] = enemy;
            break;
        }
    }
}

// Remove an enemy from the list
void removeEnemy(ENTITY* enemy) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemyList[i] == enemy) {
            enemyList[i] = NULL;
            // You can also free the memory allocated for the enemy here if necessary
            break;
        }
    }
}

// Create a new enemy
void createEnemy() {
    ENTITY* newEnemy = // code to create a new enemy here
    addEnemy(newEnemy);
}

// Check for killed enemies and remove them from the list
void checkKilledEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemyList[i] != NULL && // condition to check if enemy is killed) {
            removeEnemy(enemyList[i]);
        }
    }
}
