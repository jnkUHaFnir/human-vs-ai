#include <stdio.h>
#define DEST 6

void errorDollar() {
    printf("Invalid dollar rate.\n");
}

int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate) {
    // n is the number of rows
    double Price;
    int AirLinesCounter = 0;

    // Read the dollar rate
    while (scanf("%lf", dollarRate) != 1 || *dollarRate <= 0) {
        errorDollar();
        // Attempt to clear the buffer up to the end of the line or EOF.
        while (getchar() != '\n' && !feof(stdin));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < DEST; ++j) {
            if (scanf("%lf", &Price) != 1 || Price <= 0) {
                printf("ERROR: invalid price in airline # %d\n", i + 1); // +1 for 1-based indexing
                return -1;
            }
            flightsPrices[i][j] = Price;
        }
        AirLinesCounter++;
    }
    return AirLinesCounter;
}

int main() {
    double flightsPrices[2][DEST];
    double dollarRate;
    int n = 2; // Assuming 2 airlines for the input example
    int airlinesFilled = fillPricesTable(flightsPrices, n, &dollarRate);
    if (airlinesFilled != -1) {
        printf("Success! Airlines filled: %d\n", airlinesFilled);
    }
    return 0;
}
