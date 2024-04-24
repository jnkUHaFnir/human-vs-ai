int size;
int attempt = 0;

do {
    if (attempt > 0) {
        printf("Invalid size\n");
    }

    printf("Size of tower (0 <= x <= 23): ");
    scanf("%i", &size);

    attempt++;
} while (size > 23 || size < 0);
int size;
int error = 0;

do {
    if (error) {
        printf("Invalid size\n");
    }

    printf("Size of tower (0 <= x <= 23): ");
    scanf("%i", &size);

    if (error == 1) {
        // Code specific to second iteration
        printf("This is the second attempt\n");
    }

    error++;
} while (size > 23 || size < 0);
