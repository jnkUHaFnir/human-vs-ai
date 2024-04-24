#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void cleanData(char *data)
{
    char cleanedData[MAX_LENGTH];
    int j = 0;

    for (int i = 0; i < strlen(data); i++)
    {
        if (isalnum(data[i]) || isspace(data[i])) // Check for letters, numbers, and spaces
        {
            cleanedData[j] = data[i];
            j++;
        }
    }
    cleanedData[j] = '\0'; // Add null terminator to the end

    // Now cleanedData contains the filtered data without unwanted characters
    printf("Cleaned data: %s\n", cleanedData);
}

int main()
{
    char receivedData[] = "Some# 123 extra\n data!";

    printf("Original data: %s\n", receivedData);
    cleanData(receivedData);

    return 0;
}
