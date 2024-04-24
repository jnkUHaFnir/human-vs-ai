    #include <stdio.h>
    #include <string.h>
    
    #define OK       0
    #define NO_INPUT 1
    #define TOO_LONG 2
    static int getLine (char *prmpt, char *buff, size_t sz) {
        int ch;
    
        // Get line with buffer overrun protection. Newline is because
        // CTRL-D doesn't drop down to next line in my system.
    
        printf ("%s", prmpt);
        if (fgets (buff, sz, stdin) == NULL) {
            putchar ('\n');
            return NO_INPUT;
        }
    
        // If it was too long, there'll be no newline at the end.
        // In that case, we flush to end of line so that excess
        // doesn't affect the next call to getLine.
    
        if (buff[strlen(buff)-1] != '\n') {
            while (((ch = getchar()) != '\n') && (ch != EOF));
            return TOO_LONG;
        }
    
        // Otherwise remove newline and give string back to caller.
    
        buff[strlen(buff)-1] = '\0';
        return OK;
    }
    
    // Test program for getLine().
    
    int main (void) {
        int rc;
        char buff[10];
    
        rc = getLine ("Enter string> ", buff, sizeof(buff));
        if (rc == NO_INPUT) {
            printf ("No input\n");
            return 1;
        }
    
        if (rc == TOO_LONG) {
            printf ("Input too long\n");
            return 1;
        }
    
        printf ("OK [%s]\n", buff);
    
        return 0;
    }