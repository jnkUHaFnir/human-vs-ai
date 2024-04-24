#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **DoThis(int n, int arr[n]);

bool areArraysEqual(int n, int arr1[n], int arr2[n]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int findTarget(int n, int initialArr[n], int targetArr[n]) {
    int **currentLevel = DoThis(n, initialArr); // Get the first level output
    int level = 1; // Starting at level 1
    
    // This will efficiently check only the current level's output
    while (true) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (areArraysEqual(n, currentLevel[i], targetArr)) {
                // Cleanup
                for (int j = 0; j < n; j++) free(currentLevel[j]);
                free(currentLevel);
                return level;
            }
            
            // Not found yet, prepare for the next level
            int **newLevelOutput = DoThis(n, currentLevel[i]);
            if (i == 0) { // Cleanup previous level except the first array of the new level
                for (int j = 0; j < n; j++) if (currentLevel[j] != newLevelOutput[0]) free(currentLevel[j]);
                free(currentLevel);
            } else { // Cleanup immediately after use
                for (int j = 0; j < n; j++) free(newLevelOutput[j]);
                free(newLevelOutput);
            }
        }
        currentLevel = newLevelOutput;
        level++;
    }
}

int main() {
    int initialArr[] = {2, 3, 4, 1};
    int targetArr[] = {1, 2, 4, 3};

    int levelFound = findTarget(4, initialArr, targetArr);
    printf("Target found at level: %d\n", levelFound);

    return 0;
}
