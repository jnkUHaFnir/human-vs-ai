    #include <stdio.h>
    #include <stdlib.h>
    
    void run_program()
    {
        printf("program was run.");
    }
    
    int main() {
        char answer = 'y';
    
        do {
    
            if (answer == 'y')
            {
                run_program(); // Not main, don't call main recursively.
            }
    
            printf ("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.\n");
            scanf ("%s", &answer);
    
            if (answer != 'n' && answer != 'y')
            {
                printf ("Please enter either y or n\n");
            }
    
        } while (answer != 'n');
    
        return 0;
    }