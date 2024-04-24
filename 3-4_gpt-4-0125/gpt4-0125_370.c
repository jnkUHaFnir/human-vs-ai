#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fPtr;
    char x[100]; // Increased size to accommodate longer names
    double y;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL) // open failure
    {
        puts("File open for read failed");
        return 1; // Return an error code
    }
    else
    {
        while (fscanf(fPtr, "%s %lf", x, &y) == 2) // Read name and GPA
        {
            if (strcmp(x, "Oakley") == 0) // Check if the name is Oakley
            {
                printf("Value read = %s\n", x);
                printf("GPA = %lf \n", y);
                break; // Exit the loop once Oakley is found
            }
        }
    }

    fclose(fPtr);
    return 0;
}
