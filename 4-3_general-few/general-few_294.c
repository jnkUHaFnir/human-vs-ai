#include <stdio.h>
#include <string.h>

int main()
{
    int value[6] = {0, 0, 2, 3, 0, 0}; // Mapping of colors to values
    
    char color1[10], color2[10];
    int result;

    printf("Enter the colors: ");
    scanf("%s %s", color1, color2);
    
    if (strcmp(color1, "green") == 0 && strcmp(color2, "red") == 0)
    {
        result = value[2] * value[3]; // Assign values of green and red accordingly
        printf("Output: %d\n", result);
    }
    else
    {
        printf("Invalid color combination.\n");
    }

    return 0;
}
