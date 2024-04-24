    int fillPricesTable(double flightsPrices[][DEST], int n, double *dollarRate)
    {
        while (scanf("%lf", dollarRate) != 1 || *dollarRate <= 0) {
            errorDollar();
            for (int i; (i = getchar()) != '\n' && i != EOF;);
        }
    
        bool end_me = false;
        int i = 0;
        for (i = 0; i < n && end_me == false; ++i) {
            for (int j = 0; j < 6; ++j) {
                // no need to scan into temporary variable
                // just scan into the destination
                if (scanf("%lf", &flightsPrices[i][j]) != 1 || Price <= 0)  {
                    if (j == 0) {
                        // this is first number in the row
                        end_me = true; // using separate variable to end the outer loop
                        // because C does not have "break 2" or similar.
                        break;
                    } else {
                        errorPrice(i);
                        return -1;
                    }
                }
            }
        }
        return i; // AirLinesCounter is equal to i....
    }