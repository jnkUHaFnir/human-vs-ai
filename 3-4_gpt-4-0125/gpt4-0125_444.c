#include <stdio.h>

int main() {
    double A, B, C, D, E, F; // Use 'double' for more precision
    printf("input 1  : ");
    scanf("%lf", &A); // Use %lf to read a double
    printf("input 2 : ");
    scanf("%lf", &B); // Use %lf to read a double
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;
    printf("sum        : %lf\n", C);
    printf("difference : %lf\n", D);
    printf("product    : %lf\n", E);
    printf("quotient   : %lf\n", F);
    return 0;
}
