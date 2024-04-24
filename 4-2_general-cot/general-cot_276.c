#include <stdio.h>

int main() {
    int type, daysRented, numberOfMiles, rentalTotal, totalRevenue = 0;

    do {
        printf("Enter 0 for End, 1 for sports car, 2 for midsize, 3 for economy: ");
        scanf("%d", &type);

        if (type != 0) {
            printf("Enter days rented: ");
            scanf("%d", &daysRented);
            printf("Enter the number of miles: ");
            scanf("%d", &numberOfMiles);

            if (type == 1) {
                rentalTotal = (daysRented * 75) + (numberOfMiles * 2);
                printf("Rental Total: %d\n", rentalTotal);
                totalRevenue += rentalTotal; // Update total revenue
            }
            // Add else if statements for other car types
        }

    } while (type != 0);

    printf("Total revenue: %d\n", totalRevenue);

    return 0;
}
