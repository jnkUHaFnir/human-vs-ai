int size;
int count = 0;
do {
    if (count > 0) {
        printf("Invalid size\n");
    }
    printf("Size of tower (0 <= x <= 23): ");
    scanf("%i", &size);
    count++;
} while (size > 23 || size < 0);
