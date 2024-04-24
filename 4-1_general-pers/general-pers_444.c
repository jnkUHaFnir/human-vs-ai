#include <stdio.h>

int main() {
    int A, B, C, D, E, F; 
    printf ("Input 1: ");
    if (scanf ("%d", &A) != 1) {
        printf("Error: Input 1 must be an integer.\n");
        return 1;
    }
    
    printf ("Input 2: ");
    if (scanf ("%d", &B) != 1) {
        printf("Error: Input 2 must be an integer.\n");
        return 1;
    }
    
    C = A + B;
    D = A - B;
    E = A * B;
    
    if (B != 0) {
        F = A / B;
    } else {
        printf("Error: Division by zero\n");
        return 1;
    }
    
    printf ("Sum: %d\n", C);
    printf ("Difference: %d\n", D);
    printf ("Product: %d\n", E);
    printf ("Quotient: %d\n", F);
    
    return 0;
}
