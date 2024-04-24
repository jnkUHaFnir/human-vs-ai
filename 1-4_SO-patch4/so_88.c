    #include <stdio.h>
    #include <stdlib.h>
    char *source = NULL;
    FILE *fp = fopen("foo.txt", "r");
    if (fp != NULL) {
    	if (fseek(fp, 0L, SEEK_END) == 0) {
    		/* Get the size of the file. */
    		long bufsize = ftell(fp);
    		if (bufsize == -1) { /* Error */ }
    		/* Allocate our buffer to that size. */
    		source = malloc(sizeof(char) * bufsize + 1);
    
    		/* Read the entire file into memory. */
    		size_t newLen = fread(source, sizeof(char), bufsize, fp);
    		if (newLen == 0) {
    			fputs("Error reading file", stderr);
    		} else {
    			source[++newLen] = '\0'; /* Just to be safe. */
    		}
    	}
    	fclose(fp);
    }
    if (source != NULL) free(source); /* Don't forget to call free() later! */