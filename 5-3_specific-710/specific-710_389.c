#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void uppercase(const char source[], char destination[])
{
    int i;

    for(i = 0; i <= strlen(source); ++i)
    {
        if (source[i] >= 'a' && source[i] <= 'z')
            destination[i] = source[i] - 'a' + 'A';
        else 
            destination[i] = source[i];
    }
    
    destination[i] = '\0'; // Null-terminate the destination string
}

int main(){
    const char source[] = "cold";
    char destination[strlen(source) + 1]; // +1 for the null terminator
    
    uppercase(source, destination);
    
    printf("%s\n", destination);

    return 0;
}
