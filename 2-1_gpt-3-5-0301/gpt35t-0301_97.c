#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
    FILE *pdata;
    char buffer[1000];
    char *token, *del=",";
    int value1;
    double value2;

    pdata = fopen ("file.data", "r");

    if(pdata == NULL)
    {
        printf("unable to open file \n");
        exit(1);
    }

    while( fgets(buffer, sizeof(buffer), pdata) != NULL )
    {
        // Remove leading and trailing whitespace from the line
        char *start = buffer;
        while(isspace(*start)) start++;
        char *end = buffer + strlen(buffer) - 1;
        while(end > start && isspace(*end)) end--;
        *(end+1) = '\0';

        // Tokenize the line
        token = strtok(start, del);
        value1 = atoi(strtok(NULL, del));
        value2 = atof(strtok(NULL, del));

        printf("%s is %.3lf\n", token, value1 + value2);

    }

    fclose(pdata);

    return 0;
}
