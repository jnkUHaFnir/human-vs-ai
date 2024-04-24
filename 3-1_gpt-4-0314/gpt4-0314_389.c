#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char source[]) // Change return type to void
{
    int i;

    for(i=0; i < strlen(source); ++i) // Changed loop condition from <= to < 
    {
        if (source[i] >= 'a' && source[i] <= 'z')
            source[i] = source[i] - 'a' + 'A';
        else 
            source[i] = source[i];
    }
}

int main() {
    char input[] = "cold";    // Store the input string in a modifiable array
    uppercase(input);     // Pass the array to the uppercase function
    printf("%s\n", input);    //Print the modified string

    return 0;
}
