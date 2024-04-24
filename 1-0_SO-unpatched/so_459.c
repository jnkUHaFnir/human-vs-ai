    #include <stdio.h>
    #include <string.h>
    #define OK         0
    #define NO_INPUT   1
    #define TOO_LONG   2
    #define SMALL_BUFF 3
    static int getLine (char *prmpt, char *buff, size_t sz) {
        int ch, extra;
        // Size zero or one cannot store enough, so don't even
        // try - we need space for at least newline and terminator.
        if (sz < 2)
            return SMALL_BUFF;
        // Output prompt.
        if (prmpt != NULL) {
            printf ("%s", prmpt);
            fflush (stdout);
        }
        // Get line with buffer overrun protection.
        if (fgets (buff, sz, stdin) == NULL)
            return NO_INPUT;
        // Catch possibility of `\0` in the input stream.
        size_t len = strlen(buff);
        if (len < 1)
            return NO_INPUT;
        // If it was too long, there'll be no newline. In that case, we flush
        // to end of line so that excess doesn't affect the next call.
        if (buff[len - 1] != '\n') {
            extra = 0;
            while (((ch = getchar()) != '\n') && (ch != EOF))
                extra = 1;
            return (extra == 1) ? TOO_LONG : OK;
        }
        // Otherwise remove newline and give string back to caller.
        buff[len - 1] = '\0';
        return OK;
    }