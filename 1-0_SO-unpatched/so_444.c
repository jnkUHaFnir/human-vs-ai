    #include <stdio.h>
    
    int main(int argc, int **argv)
    {
        int A, B, C, D, E, F; 
        printf ("input 1  : ");
        if (scanf ("%d", &A) != 1 || A == 0) {
            fprintf (stderr, "error: invalid input - A.\n");
            return 1;
        }
        printf ("input 2 : ");
        if (scanf ("%d", &B) != 1) {
            fprintf (stderr, "error: invalid input - B.\n");
            return 1;
        }
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