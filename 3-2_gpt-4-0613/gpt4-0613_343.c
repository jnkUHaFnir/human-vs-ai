#include <ctype.h>
#include <string.h>

name[0] = toupper(name[0]); // Make first letter upper case

for(i = 1; i < strlen(name); i++){
    if(isspace(name[i - 1])) // If the previous character was a space
        name[i] = toupper(name[i]); // Convert to upper
    else
        name[i] = tolower(name[i]); // Convert to lower
}
char *pos;
if ((pos=strchr(name, '\n')) != NULL)
    *pos = '\0';
