    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #define NAMESTRLEN 15
    int main(void) {
	    char str_name[NAMESTRLEN];
	    size_t slen;
	    printf("Please enter your first name to begin: ");
	    if (fgets(str_name, NAMESTRLEN, stdin) == NULL) {
		    printf("Error from fgets()\n");
		    return 1;
	    }
	    slen = strlen(str_name);
	    if (slen > 0 && str_name[slen-1] == '\n') {
		    str_name[slen-1] = '\0';
	    } else {
            printf("User entered too many characters\n");
		    return 1;
        }
	    if (!*str_name) {
		    printf("No name entered\n");
		    return 1;
	    }
	    str_name[0] = toupper((unsigned char)str_name[0]);
	    printf("Hi %s.\n", str_name);
	    return 0;
    } 