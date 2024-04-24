	#include <stddef.h>
	#include <stdlib.h>
	#include <stdio.h>
	int main(void)
	{
		char *name = NULL;
		size_t length = 0;
		size_t size = 0;
		int ch;
		while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r')
		{
			if (length + 1 >= size) {
				char *new_name = realloc(name, size += 10);  // +10 ... or whatever length you expect.
				if (!new_name) {
					free(name);
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