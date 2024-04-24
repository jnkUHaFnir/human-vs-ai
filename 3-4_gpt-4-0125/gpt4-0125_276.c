scanf("%d", &type);
totalRevenue += rentalTotal;
do {
    printf("Enter 0 to End, 1 for sports car, 2 for midsize, 3 for economy: ");
    scanf("%d", &type);
    
    if (type == 0) break; // If user wants to end, break the loop immediately

    printf("Enter days rented: ");
    scanf("%d", &daysRented);

    printf("Enter the number of miles: ");
    scanf("%d", &numberOfMiles);

    if (type == 1) {
        rentalTotal = (daysRented * 75) + (numberOfMiles * 2);
    } // Add else if for other types (2 and 3) with their calculations

    totalRevenue += rentalTotal; // Calculate total revenue
    printf("Total rental cost for this vehicle: %d\n", rentalTotal); // Indicating total per vehicle (optional)
} while (type != 0);

printf("Total revenue: %d\n", totalRevenue); // Print the total revenue
