int size;
int firstIteration = 1;

do {
    if (!firstIteration && (size > 23 || size < 0)) {
        printf("Invalid size\n");
    }
    
    printf("Size of tower (0 <= x <= 23): ");
    scanf("%i", &size);
    
    firstIteration = 0;
} while (size > 23 || size < 0);
