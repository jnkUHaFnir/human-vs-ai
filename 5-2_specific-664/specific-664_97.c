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
        printf("Unable to open file \n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), pdata) != NULL)
    {
        if (strlen(buffer) < 2) // Check for empty line
        {
            continue;
        }

        token = strtok(buffer, del);
        if (token == NULL)
        {
            printf("Invalid format\n");
            continue;
        }
        
        char *val1_str = strtok(NULL, del);
        char *val2_str = strtok(NULL, del);

        if (val1_str == NULL || val2_str == NULL)
        {
            printf("Invalid format\n");
            continue;
        }
        
        value1 = atoi(val1_str);
        value2 = atof(val2_str);

        printf("%s is %.3lf\n", token, value1 + value2);
    }

    fclose(pdata);

    return 0;
}
