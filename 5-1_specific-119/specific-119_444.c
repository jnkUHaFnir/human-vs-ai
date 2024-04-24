#include <stdio.h>

int main(int argc, int **argv)
{
    float A, B; 
    int C, D, E, F;
    
    printf ("input 1  : ");
    scanf ("%f", &A);
    
    printf ("input 2 : ");
    scanf ("%f", &B);
    
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;
    
    printf ("sum  : %d\n", C);
    printf ("difference : %d\n", D);
    printf ("product  : %d\n", E);
    printf ("quotient : %d\n", F);
    
    return 0;
}
