    // Like "ENEMY enemies[100]", but from the heap
    ENEMY* enemies = malloc(100 * sizeof(ENEMY));
    // You can index pointers just like arrays.
    enemies[0] = CreateEnemy();
    // Make the array bigger
    enemies = realloc(enemies, 200 * sizeof(ENEMY));
    // Clean up when you're done.
    free(enemies);
   