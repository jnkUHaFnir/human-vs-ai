#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *pdata;
    char buffer[1000];
    char *token, *del = ",";
    int value1;
    double value2;

    pdata = fopen("file.data", "r");

    if (pdata == NULL)
    {
        printf("unable to open file \n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), pdata) != NULL)
    {
        token = strtok(buffer, del);

        if (token == NULL)
        {
            continue; // Skip empty line
        }

        value1 = atoi(strtok(NULL, del));

        if ((token = strtok(NULL, del)) == NULL)
        {
            continue; // Skip invalid line
        }

        value2 = atof(token);

        printf("%s is %.3lf\n", token, value1 + value2);
    }

    fclose(pdata);

    return 0;
}
