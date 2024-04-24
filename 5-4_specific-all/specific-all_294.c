#include <stdio.h>

int main()
{
    const char *colors[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    char color1[10], color2[10];
    int value1, value2, result;

    printf("Enter the first color: ");
    scanf("%s", color1);

    printf("Enter the second color: ");
    scanf("%s", color2);

    // Find values for color1 and color2
    for (int i = 0; i < 10; i++) {
        if (strcmp(color1, colors[i]) == 0) {
            value1 = values[i];
        }
        if (strcmp(color2, colors[i]) == 0) {
            value2 = values[i];
        }
    }

    result = value1 * value2;
    printf("Result: %d\n", result);

    return 0;
}
