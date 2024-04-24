    #include <stdio.h>
    #include <stdlib.h>
    
    void run_program()
    {
        printf("program was run.");
    }
    
    int main() {
        char answer[2] = "y\0";
    
        do {
    
            if (answer[0] == 'y')
            {
                run_program(); /* Not main, don't call main recursively. */
            }
    
            printf ("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.\n");
            scanf ("%s", answer);
    
            if (answer[0] != 'n' && answer[0] != 'y')
            {
                printf ("Please enter either y or n\n");
            }
    
        } while (answer[0] != 'n');
    
        return 0;
    }