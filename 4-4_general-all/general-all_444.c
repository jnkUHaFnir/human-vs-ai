#include <stdio.h>

int main() {
    float A, B, C, D, E, F; 
    printf ("input 1  : ");
    scanf ("%f", &A);
    printf ("input 2 : ");
    scanf ("%f", &B);
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;
    printf ("sum  : %f\n", C);
    printf ("difference : %f\n", D);
    printf ("product  : %f\n", E);
    printf ("quotient : %f\n", F);
    return 0;
}
