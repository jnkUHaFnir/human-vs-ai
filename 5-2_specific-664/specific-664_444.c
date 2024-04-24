#include <stdio.h>

int main()
{
    double A, B;
    double C, D, E, F;

    printf("input 1 : ");
    scanf("%lf", &A);

    printf("input 2 : ");
    scanf("%lf", &B);

    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;

    printf("sum       : %f\n", C);
    printf("difference: %f\n", D);
    printf("product   : %f\n", E);
    printf("quotient  : %f\n", F);

    return 0;
}
