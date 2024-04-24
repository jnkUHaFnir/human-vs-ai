int size;
int isFirstLoop = 1;
do {
    if (!isFirstLoop) { 
        printf("Invalid size\n");
    }
    printf("Size of tower (0 <= x <= 23): ");
    scanf("%i", &size);
    isFirstLoop = 0;
} while (size > 23 || size < 0);
