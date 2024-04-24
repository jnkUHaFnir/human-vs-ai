    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    int main(){
    	int myArray[240][30];
    	char line[240];
    	char *token;
    	int i, n, j;
    	FILE *fp;
    	fp=fopen("array_list.txt", "rt");
    	i = 0;
    	while(fgets(line, sizeof(line), fp))
    	{
    		j = 0;
    		token = strtok(line, " ");  // initialize line tokens
    		while(1)  // note the infinite loop here to avoid calling strtok twice
    		{
    			n = atoi(token);
    			myArray[i][j] = n;
    			printf("%d ", myArray[i][j]);
    			token = strtok(NULL, " ");  // next token
    			if (token==NULL) break;    // no more items: next line please
    			j++;
    		}
    
    		printf("\n");
    		i++;
    	}
    	return 0;
    }