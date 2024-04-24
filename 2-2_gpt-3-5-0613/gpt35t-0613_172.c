#include <stdio.h>
#include <string.h>

int main() {
    char answer[2] = "";

    while (strcmp(answer, "y") != 0 && strcmp(answer, "n") != 0) {
        printf("\n\nWould you like to run the program again? Type y or n. Then, hit Enter.");
        scanf(" %1s", answer);

        if (strcmp(answer, "y") == 0) {
            // Restart program
        } else if (strcmp(answer, "n") != 0) {
            printf("\nERROR: Invalid input was provided. Your answer must be either y or n. Hit Enter to continue.");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    return 0;
}
