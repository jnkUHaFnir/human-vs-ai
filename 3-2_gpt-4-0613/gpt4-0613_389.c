#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void uppercase(char source[]) {
 int i;

 for(i=0; i<strlen(source); ++i)
    if (source[i]>= 'a' && source[i]<= 'z')
        source[i]= source[i]-'a' +'A';
}

int main(){
    char source[] = "cold";
    uppercase(source);
    printf("%s\n", source); // This will output: COLD

    return 0;
}
