#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        if (buffer[0] == '\n' || buffer[0] == '\r') {
            continue; // Skip empty lines
        }

        token = strtok(buffer, del);
        if (token == NULL) {
            continue; // Skip lines with no token
        }

        value1 = atoi( strtok(NULL, del) );
        value2 = atof( strtok(NULL, del) );

        printf("%s is %.3lf\n", token, value1 + value2);

    }

    fclose( pdata );

    return 0;
}
