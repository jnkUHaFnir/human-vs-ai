int fillPricesTable(double flightsPrices[][DEST], int n, double* dollarRate)
{
    // n is the number of rows
    double Price;
    int  AirLinesCounter = 0;

    while (scanf("%lf", dollarRate) != 1 || *dollarRate <= 0)
    {
        errorDollar();
        fflush(stdin);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (scanf("%lf", &Price) != 1 || Price <= 0)
            {
                printf("ERROR: invalid price in airline # %d\n", i+1);
                return -1;
            }
            flightsPrices[i][j] = Price;
        }
        AirLinesCounter++;
        if (scanf("%lf", &Price) == EOF)
            break;
    }
    return AirLinesCounter;
}
