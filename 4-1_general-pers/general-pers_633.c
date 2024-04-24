#include <stdio.h>

#define DEST 6

void errorDollar() {
    printf("ERROR: invalid dollar rate\n");
}

int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate) {
    double Price;
    int AirLinesCounter = 0;

    if (scanf("%lf", dollarRate) == EOF || *dollarRate <= 0) {
        errorDollar();
        return -1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < DEST; ++j) {
            if (scanf("%lf", &Price) == EOF || Price <= 0) {
                printf("ERROR: invalid price in airline # %d\n", i);
                return -1;
            }
            flightsPrices[i][j] = Price;
        }
        AirLinesCounter++;
    }

    return AirLinesCounter;
}
