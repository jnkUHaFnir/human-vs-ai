#include <stdio.h>

#define DEST 6

// Add error messages functions, if needed.

void errorDollar() {}

int fillPricesTable(double flightsPrices[][DEST], int n, double *dollarRate) {
  // n is the number of rows
  double Price;

  while (scanf("%lf", dollarRate) == EOF || *dollarRate <= 0) {
    errorDollar();
    fflush(stdin);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < DEST; ++j) {
      if (scanf("%lf", &Price) == EOF) {
        return i; // Return the number of successful airlines read so far
      } else if (Price <= 0) {
        printf("ERROR: invalid price in airline # %d\n", i + 1);
        return -1;
      }
      flightsPrices[i][j] = Price;
    }
  }
  return n;
}

int main() {
  double flightsPrices[2][DEST];
  double dollarRate = 0.0;
  int result = fillPricesTable(flightsPrices, 2, &dollarRate);

  printf("result = %d\n", result);
  return 0;
}
