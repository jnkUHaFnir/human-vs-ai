    #include <stdio.h>
    #define MAXBUFLEN 1000000
    char source[MAXBUFLEN];
    FILE *fp = fopen("foo.txt", "r");
    if (fp != NULL) {
    	if (fread(source, sizeof(char), MAXBUFLEN, fp) == 0) {
    		fputs("Error reading file", stderr);
    	}
    	fclose(fp);
    }