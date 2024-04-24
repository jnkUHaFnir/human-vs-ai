if (scanf("%lf", dollarRate) != 1 || *dollarRate <= 0) {
    errorDollar();
    // flushing stdin is generally not recommended; it's undefined behavior in C.
    // fflush(stdin);
    return -1;
}
#include <stdio.h>

#define DEST 6

int fillPricesTable(double flightsPrices[][DEST], int n, double *dollarRate) {
    double Price;
    int AirLinesCounter = 0;

    // Read the dollar rate
    if (scanf("%lf", dollarRate) != 1 || *dollarRate <= 0) {
        errorDollar();
        return -1;
    }

    // Read the prices table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < DEST; ++j) {
            if (scanf("%lf", &Price) != 1 || Price <= 0) {
                printf("ERROR: invalid price in airline # %d\n", i + 1);  // The airline counter should start from 1
                return -1;
            }
            flightsPrices[i][j] = Price;
        }
        AirLinesCounter++;
    }
    return AirLinesCounter;
}

void errorDollar() {
    printf("ERROR: Invalid dollar rate\n");
}

int main() {
    double dollarRate;
    double pricesTable[3][DEST];  // Assuming that the number of airlines (rows) is 3
    int airlines;

    airlines = fillPricesTable(pricesTable, 3, &dollarRate);
    if (airlines != -1) {
        printf("Dollar rate: %.2f\n", dollarRate);
        for (int i = 0; i < airlines; ++i) {
            for (int j = 0; j < DEST; ++j) {
                printf("%.2f ", pricesTable[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
