    #include <stdio.h>
    #include <stdlib.h>
    
    int main (void)
    {
        #define SIZE 100
        char* username[100]; 
        int i;
        int p;
    
        /* Read words into array */
        for(i = 0; i < 3; i++)
        {
            username[i] = calloc(SIZE, sizeof(char)); 
    		printf("Enter word %d:", i+1);
            // DANGER! What if user enters more than 99 + NULL character?
            scanf("%s",username[i]);
        }
    
        /* Print out array */
        for (p = 0; p < 3; p++) {
    		printf("%s\n", username[p]);
            free( username[p] );
        }
    
        return 0;
    }