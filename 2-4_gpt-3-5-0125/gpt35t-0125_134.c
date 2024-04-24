int validate(int low, int high) {
    int s;

    do {
        printf("Selection: ");
        scanf("%d", &s); // You need to pass the address of the variable to scanf
        if (s < low || s > high) {
            printf("Invalid Input, try again: ");
        }
    } while (s < low || s > high);

    return s;
}
Valid_Selection = validate(low, high);
