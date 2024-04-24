#include <stdio.h>
#include <string.h>

int main()
{
    char firstname[50];
    char lastname[50];
    char nothing[0];

    printf("pleas type input file, and output file please type legibly pwease\n ");
    scanf("%s %s", firstname, lastname);

    if (strcmp(firstname, lastname) == 0)
    {
        printf("Error: First and last name cannot be the same.");
    }
    else
    {
        printf("Names are different");
    }
    return 0;
}
