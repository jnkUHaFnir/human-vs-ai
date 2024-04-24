#include <stdio.h>

int main() {
    int type, daysRented, numberOfMiles, rentalTotal, totalRevenue = 0;

    do {
        printf("Enter 0 to end, 1 for sports car, 2 for midsize, 3 for economy: ");
        scanf("%d", &type);

        if (type != 0) {
            printf("Enter days rented: ");
            scanf("%d", &daysRented);
            printf("Enter the number of miles: ");
            scanf("%d", &numberOfMiles);

            if (type == 1) {
                rentalTotal = (daysRented * 75) + (numberOfMiles * 2);
            } else if (type == 2) {
                rentalTotal = (daysRented * 60) + (numberOfMiles * 1.5);
            } else if (type == 3) {
                rentalTotal = (daysRented * 50) + (numberOfMiles);
            }

            totalRevenue += rentalTotal;
            printf("Total revenue so far: %d\n", totalRevenue);
        }

    } while (type != 0);

    return 0;
}
