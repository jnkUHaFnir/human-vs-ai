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
        printf("Unable to open file\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), pdata) != NULL)
    {
        // Check if line is empty (or only contains newlines)
        if (strcmp(buffer, "\n") == 0 || strcmp(buffer, "\r\n") == 0) {
            continue; // Skip this iteration
        }

        // Try to get the first token
        token = strtok(buffer, del);

        // If token or the next tokens are NULL, continue to the next line
        if (token == NULL || (strtok(NULL, del) == NULL) || (strtok(NULL, del) == NULL)) {
            printf("Error: Line format incorrect or missing data.\n");
            continue; // Skip this line as it doesn't conform to the expected format
        }

        // Reset to buffer to parse it from the start again as we need the first token
        // Parsing again because previous checks might have modified it
        strtok(buffer, del);
        
        // We parse the integers again, because the previous conditional structure
        // moved the internal state pointer of strtok past the integers
        value1 = atoi(strtok(NULL, del));
        value2 = atof(strtok(NULL, del));

        printf("%s is %.3lf\n", token, value1 + value2);
    }

    fclose(pdata);

    return 0;
}
