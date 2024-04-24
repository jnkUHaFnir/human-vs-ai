int validate(int low, int high) {
    int s;

    do {
        scanf("%d", &s);
        if (s < 1 || s > 3)
            printf("Invalid Input, try again: ");
    } while (s < 1 || s > 3);

    return s;
}
