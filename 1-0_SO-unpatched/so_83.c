    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    
    bool concatenateString(char **dest, size_t *size, char *stringToAdd)
    {
    	bool retVal = true;
        char *dest_old = *dest;
        *size += strlen(stringToAdd);
    
    	if (*dest == NULL)
    	{
            *size += 1; // to add null terminator of string
    		*dest = calloc(1, size);
    	}
    	else
    	{
    		*dest = realloc(*dest, size);
    	}
    
    	if (dest == NULL)
    	{
            free(dest_old);
    		retVal = false;
    	}
    	else
    	{
    		strcat(*dest, stringToAdd);
    	}
    
    	return retVal;
    }
    
    int main()
    {
    	char newString[32] = {0};
    	int number;
        size_t size = 0;
    
    	char *data1 = NULL;
    
    	printf("Insert a string:");
    	scanf(" %s", newString);
    	if (concatenateString(&data1, &size, newString))
    	{
    		printf("Insert a number:");
    		scanf(" %d", &number);
    		sprintf(newString, "%03d", number);
    		if (concatenateString(&data1, &size, newString) )
    		{
    			printf("Insert a string:");
    			scanf(" %s", newString);
    			if (concatenateString(&data1, &size, newString))
                   printf("%s\n", data1);
    		}
    	}
    
    	free(data1);
    }