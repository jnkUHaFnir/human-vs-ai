scanf("%d", &type);
printf("%i\n", rentalTotal);
do {
    printf("Enter 0 to quit, or 1 for sports car, 2 for midsize, 3 for economy: ");
    scanf("%d", &type);

    if (type != 0) {
        printf("Enter days rented: ");
        scanf("%d", &daysRented);
        printf("Enter the number of miles: ");
        scanf("%d", &numberOfMiles);

        if (type == 1) {
            rentalTotal = (daysRented * 75) + (numberOfMiles * 2);
            totalRevenue += rentalTotal;
            printf("Total revenue for this rental: %i\n", rentalTotal);
        }
    }
} while (type != 0);

printf("Total revenue for all rentals: %i\n", totalRevenue);
