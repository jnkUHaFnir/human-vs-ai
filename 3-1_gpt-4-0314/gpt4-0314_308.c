#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("file.txt", "r");
    char string[100];
    char found[100];
    char *result;
    const char fetch[11] = "learning";

    while (fgets(string, 100, fp))
    {
        strcpy(found, string);
        printf("Your result is: %s", found);

        result = strstr(found, fetch);
        
        if (result != NULL) {
	    printf("Found \"%s\" at position: %s\n", fetch, result);
        }
    }
    fclose(fp);
    
    return 0;
}
