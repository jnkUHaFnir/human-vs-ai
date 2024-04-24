int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate)
{
    double Price;
    int AirLinesCounter = 0;

    do {
        if (scanf("%lf", dollarRate) != 1 || *dollarRate <= 0) {
            errorDollar();
            fflush(stdin);
        }
    } while (*dollarRate <= 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (scanf("%lf", &Price) != 1 || Price <= 0) {
                printf("ERROR: invalid price in airline # %d\n", i);
                return -1;
            }
            flightsPrices[i][j] = Price;
        }
        AirLinesCounter++;
    }

    return AirLinesCounter;
}
