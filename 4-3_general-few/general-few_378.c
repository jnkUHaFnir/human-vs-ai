int size;
int isFirstLoop = 1; // Flag to indicate the first loop iteration

do {
    if (!isFirstLoop) {
        printf("Invalid size\n");
    }
    printf("Size of tower (0 <= x <= 23): ");
    scanf("%i", &size);

    isFirstLoop = 0; // Set the flag to false after the first iteration
} while (size > 23 || size < 0);
