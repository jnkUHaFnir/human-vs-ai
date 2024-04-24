#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    char buffer[256];
    int valid_input;

    do {
        printf("How old are you?\n");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input.\n");
            return 1;
        }

        valid_input = sscanf(buffer, "%d", &age);
        
        if (valid_input != 1) {
            printf("Error, invalid input. Please enter a valid age.\n");
            continue;
        }

        if (age <= 0 || age > 150) {
            printf("Error, invalid age. Please enter a valid age between 1 and 150.\n");
            continue;
        }

        printf("Cool.\n");
        break;

    } while (1);

    return 0;
}
