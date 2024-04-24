	#include <stddef.h>
	#include <stdlib.h>
	#include <stdio.h>
	int main(void)
	{
		char *name = NULL;
		size_t length = 0;
		size_t size = 0;
        size_t const buffer_growth = 10;  // +10 ... or whatever length you expect
		int ch;
		while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r')
		{
			if (length + 1 >= size) {
                if(size + buffer_growth <= size) {  // we reached or overflow the max
                    break;                          // object size on the platform
                }
				char *new_name = realloc(name, size += buffer_growth);
				if (!new_name) {					free(name);
					fputs("Memory allocation failed :(\n\n", stderr);
					return EXIT_FAILURE;
				}
				name = new_name;
			}
		
			name[length++] = ch;
			name[length] = '\0';
		}
		printf("\"%s\"\n", name);
	}