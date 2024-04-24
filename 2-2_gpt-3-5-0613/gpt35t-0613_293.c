#define GREEN 2
#define RED 3
#include <stdio.h>

#define GREEN 2
#define RED 3

int main()
{
    char bands, color1, color2;
    int mult;

    printf("Select how many bands the resistor has");
    printf("\n A. 4 bands");
    printf("\n B. 5 bands");
    printf("\n C. 6 bands");
    scanf("%c", &bands);

    switch (bands)
    {
        case 'a':
        case 'A':
            printf("Enter the colors");
            scanf(" %c %c", &color1, &color2); // Notice the additional space before %c to consume the newline character
            mult = GREEN * RED;
            printf("%d\n", mult);
            break;
    }

    getchar();
    return 0;
}
