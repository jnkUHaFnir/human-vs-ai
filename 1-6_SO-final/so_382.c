    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define BUFFSIZE 10
    int convertbinary(char *binarynumber);
    int
    main(int argc, char *argv[]) {
	    int binaryreturn;
	    char *bnumber;
	    size_t currsize = BUFFSIZE, len;
	    const char *quit = "q";
	    bnumber = malloc(currsize * sizeof(*bnumber));
	    if (bnumber == NULL) {
		    printf("Cannot allocate memory!\n");
		    exit(EXIT_FAILURE);
	    }
	    printf("Enter binary byte or type q to quit: ");
	    while (fgets(bnumber, currsize, stdin) != NULL) {
		    len = strlen(bnumber);
		    if (len > 0) {
			    if (bnumber[len-1] == '\n') {
				    bnumber[len-1] = '\0';
			    }  else {
				    printf("Buffer Exceeds length of %d\n", BUFFSIZE);
				    exit(EXIT_FAILURE);
			    }
		    }
		    if (!*bnumber) {
			    printf("No number entered.\n");
			    printf("\nEnter binary byte or type q to quit: ");
		    } else {
			    if (strcmp(bnumber, quit) == 0) {
				    printf("Goodbye\n");
				    exit(EXIT_FAILURE);
			    }
			    binaryreturn = convertbinary(bnumber);
			    printf("binary number = %d\n", binaryreturn);
			    printf("\nEnter binary byte or type q to quit: ");
		    }
	    }		
	    free(bnumber);
	    return 0;
    }
    int 
    convertbinary(char *binarynumber) {
        int val = 0;
        while (*binarynumber != '\0') {
            val = 2 * val + (*binarynumber++ - '0');
        }
        return val;
    }