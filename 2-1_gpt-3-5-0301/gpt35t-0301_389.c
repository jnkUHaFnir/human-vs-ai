#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char source[], char result[])
{
    int i;
    for(i=0; i<=strlen(source); ++i) {
        if (source[i]>= 'a' && source[i]<= 'z')
            result[i]= source[i]-'a' +'A';
        else 
            result[i]=source[i];
    }
    result[i] = '\0'; // add null terminator at end of result string
}

int main(){
    char source[] = "cold";
    char result[strlen(source)+1]; // create result array with same size as source, plus space for null terminator
    uppercase(source, result);
    printf("%s", result);
    return 0;
}