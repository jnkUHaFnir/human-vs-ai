    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(){
        const char *spaces = "\n\t ";
    	int myArray[240][30];
    	char line[240];
    	char *token;
    	int i, n, j;
    	FILE *fp;
    	fp=fopen("array_list.txt", "rt");
    	i = 0;
    	while(fgets(line, sizeof(line), fp))
    	{
    		j = 1;
    		token = strtok(line, spaces);  // initialize line tokens
    		while(token)  // just in case the line is empty
    		{
    			n = atoi(token);  // strtol + error checking would be better
    			myArray[i][j] = n;
    			j++;
    			printf("%d ", myArray[i][j]);
    			token = strtok(NULL, spaces);  // next token
    			if (token==NULL) break;    // no more items: next line please
    		}
            myArray[i][0] = j;  // use first array position to store the size
    
    		printf("\n");
    		i++;
    	}
    	return 0;
    }