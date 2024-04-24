	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define bufSize 1024
	int main(int argc, char *argv[])
	{
		FILE* fp;
		if (argc != 2)
		{
			fprintf(stderr, "Usage: %s <soure-file>\n", argv[0]);
			return 1;
		}
		if ((fp = fopen(argv[1], "r")) == NULL)
		{ /* Open source file. */
			perror("fopen source-file");
			return 1;
		}
		size_t n = 0;
		char (*buf)[4000] = malloc(bufSize * 4000);
		if (!buf) {
			fprintf(stderr, "Error - Failed to allocate memory.\n");
			fclose(fp);
			return 1;
		}
		while (fgets(buf[n], bufSize, fp) != NULL)
		{
			n++;
			if (n == 4000) {
				/* do something */
				// ...
				n = 0;
			}
		
		}
		fclose(fp);
		return 0;
	}