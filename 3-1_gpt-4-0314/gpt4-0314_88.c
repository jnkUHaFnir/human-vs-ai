#include <stdio.h>
#include <stdlib.h>

int main()
{
    char source[1000000] = { 0 };

    FILE *fp = fopen("TheFile.txt", "r");
    if(fp != NULL)
    {
        size_t read = fread(source, 1, sizeof(source) - 1, fp);
        
        source[read] = '\0'; // Ensuring null termination
        fclose(fp);
    }

    for(int x = 0; source[x] != '\0'; x++)
    {
        //Process chars
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char source[1000000] = { 0 };
    int symbol;

    FILE *fp = fopen("TheFile.txt", "r");
    if(fp != NULL)
    {
        int index = 0;
        while((symbol = getc(fp)) != EOF)
        {
            source[index++] = (char)symbol;
        }
        source[index] = '\0'; // Ensuring null termination
        fclose(fp);
    }

    for(int x = 0; source[x] != '\0'; x++)
    {
        //Process chars
    }

    return 0;
}
