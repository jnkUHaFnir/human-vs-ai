#include <stdio.h>
int main()
{
    int i;
    char** t;
    t=(char**)malloc(16*sizeof(char*));
for(i<0;i<100;i++)
{
    *t[i]=(char*)malloc(16*sizeof(char));
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char** t;
    t = (char**)malloc(16 * sizeof(char*));

    for (i = 0; i < 16; i++)
    {
        t[i] = (char*)malloc(16 * sizeof(char));
    }

    // Use the allocated memory here
    
    for (i = 0; i < 16; i++)
    {
        free(t[i]);
    }
    
    free(t);

    return 0;
}
