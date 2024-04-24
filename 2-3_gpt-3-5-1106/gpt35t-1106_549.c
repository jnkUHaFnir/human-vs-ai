#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *input = (char *)malloc(256 * sizeof(char));
    char temp;
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%s", input);
    
    j = strlen(input) - 1;

    while (i < j)
    {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }
    printf("Reverse = %s\n", input);

    free(input); // don't forget to free the memory allocated with malloc

    return 0;
}
