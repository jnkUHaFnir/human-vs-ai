#include <stdio.h>

#define DEST 6

void errorDollar() {
    printf("ERROR: Invalid dollar rate input\n");
}

int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate) {
    // n is the number of rows
    double Price;
    int AirlinesCounter = 0;

    if (scanf("%lf", dollarRate) == EOF || *dollarRate <= 0) {
        errorDollar();
        return -1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%lf", &Price) == EOF || Price <= 0) {
            printf("ERROR: Invalid price in airline # %d\n", i);
            return -1;
        }
        flightsPrices[i][0] = Price;

        for (int j = 1; j < DEST; ++j) {
            if (scanf("%lf", &Price) == EOF || Price <= 0) {
                printf("ERROR: Invalid price in airline # %d\n", i);
                return -1;
            }
            flightsPrices[i][j] = Price;
        }

        AirlinesCounter++;

        if (scanf("%lf", &Price) == EOF) {
            break;
        }
    }

    return AirlinesCounter;
}

int main() {
    double flightsPrices[2][DEST];
    double dollarRate;
    int result = fillPricesTable(flightsPrices, 2, &dollarRate);

    if (result != -1) {
        printf("Successfully filled prices table\n");
    }

    return 0;
}
