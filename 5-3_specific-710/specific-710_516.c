#include <stdio.h>

int main() {
    int age;
    int validInput;

    do {
        printf("How old are you?\n");
        validInput = scanf("%d", &age);

        if (validInput != 1) {
            printf("Error, retry: \n");
            // Clear input buffer
            while(getchar() != '\n');
        } else {
            printf("Cool.\n");
            break;
        }
    } while(1);

    return 0;
}
