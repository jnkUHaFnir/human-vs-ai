int numOfDef;
while (1) {
    printf("Enter a positive number: ");
    if (scanf("%d", &numOfDef) != 1 || numOfDef <= 0) {
        printf("Invalid input. Try again.\n");
        // consume any remaining input characters to prevent infinite loop
        while (getchar() != '\n');
    } else {
        break;
    }
}
char input[100];
int numOfDef;
while (1) {
    printf("Enter a positive number: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &numOfDef) != 1 || numOfDef <= 0) {
        printf("Invalid input. Try again.\n");
    } else {
        break;
    }
}
