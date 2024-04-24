#include <stdio.h>

int main()
{
    float A, B, C, D, E, F; 
    printf ("input 1  : ");
    scanf ("%f", &A);
    printf ("input 2 : ");
    scanf ("%f", &B);
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;
    printf ("sum  : %.2f\n", C);
    printf ("difference : %.2f\n", D);
    printf ("product  : %.2f\n", E);
    printf ("quotient : %.2f\n", F);
    return 0;
}
