#include <stdio.h>
#include <ctype.h>

int main() {
    int any_integer;
    char any_string[30];
    float any_float;

    do {
        printf("Please enter an integer, one-word string, and a float in one line: ");
        scanf("%i %29s %f", &any_integer, any_string, &any_float);

        if (any_integer == 999) {
            break;
        }

        while (any_integer < 0 || any_integer > 50) {
            printf("\n*** Invalid integer.\nPlease enter a value between 1 and 50: ");
            scanf("%i", &any_integer);
        }

        while (any_float < 0 || any_float > 50) {
            printf("\n*** Invalid float.\nPlease enter a value between 1 and 50: ");
            scanf("%f", &any_float);
        }

        for (int i = 0; any_string[i] != '\0'; i++) {
            if (!isalpha(any_string[i])) {
                any_string[i] = '\0';
                break;
            }
        }
        printf("The integer is: %i\n", any_integer);
        printf("The string is: %s\n", any_string);
        printf("The float is: %f\n", any_float);

    } while (1); // This creates an infinite loop

    return 0;
}
