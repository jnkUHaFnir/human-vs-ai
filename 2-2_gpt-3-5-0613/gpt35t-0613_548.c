#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *directions[3];
    for(int i = 0; i < 3; i++) {
        directions[i] = (char*)malloc(sizeof(char)*100); // Allocate memory for each string
        scanf("%s", directions[i]);
    }
    
    for(int i = 0; i < 3; i++) {
        printf("%s\n", directions[i]);
        free(directions[i]); // Free the allocated memory
    }
    
    return 0;
}
