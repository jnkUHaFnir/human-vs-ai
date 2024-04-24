names = (char**)malloc(amount * sizeof(char*)); // Allocate an array of char pointers
fgets(names[i], MAX_CHARS, stdin); // Read full line including newline character
strcpy(temp, names[j]);
strcpy(names[j], names[i]);
strcpy(names[i], temp);
#include <string.h>

if (strcmp(names[j], names[i]) < 0)
names[i] = (char*)realloc(names[i], (strlen(names[i]) + 1) * sizeof(char)); // +1 for null terminator
for (i = 0; i < amount; i++)
{
    free(names[i]);
}
free(names);
