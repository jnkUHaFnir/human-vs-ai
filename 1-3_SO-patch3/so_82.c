    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    
    bool concatenateString(char **dest, char *stringToAdd)
    {
    	bool retVal = true;
        static size_t size =0;
        size += strlen(stringToAdd);
    
    	if (*dest == NULL)
    	{
            size++;
    		*dest = calloc(1, size);
    	}
    	else
    	{
    		*dest = realloc(*dest, size);
    	}
    
    	if (dest == NULL)
    	{
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
    
    	char *data1 = NULL;
    
    	printf("Insert a string:");
    	scanf(" %s", newString);
    	if (concatenateString(&data1, newString))
    	{
    		printf("Insert a number:");
    		scanf(" %d", &number);
    		sprintf(newString, "%03d", number);
    		if (concatenateString(&data1, newString) )
    		{
    			printf("Insert a string:");
    			scanf(" %s", newString);
    			if (concatenateString(&data1, newString))
                   printf("%s\n", data1);
    		}
    	}
    
    	free(data1);
    }