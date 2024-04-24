Valid_Selection = validate(low, high);
while (s < low || s > high);
int validate(int low, int high) {
    int selection;

    do {
        printf("Selection: ");
        scanf("%d", &selection);
        if (selection < low || selection > high) {
            printf("Invalid input. Please enter a number between %d and %d.\n", low, high);
        }
    } while (selection < low || selection > high);

    return selection;
}
int Valid_Selection = validate(1, 3);
