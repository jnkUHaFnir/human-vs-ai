#include <stdio.h>
#include <string.h>

int main() {
    char answer[4]; // Make sure to allocate enough space for "yes" and the null terminator

    int guess;
    int diceRoll4 = 0;

    printf("Would you like to guess your next dice? Y/N \n");
    scanf("%s", answer); // Read as a string

    if (strcmp(answer, "yes") == 0) { // Compare strings using strcmp
        printf("What is your guess?\n");
        printf("Please enter your number \n");
        scanf("%d", &guess);

        if (guess > diceRoll4) {
            printf("You got it wrong, too high!");
        }
        else if (guess < diceRoll4) {
            printf("You got it wrong, too low!");
        }
        else {
            printf("You got it right");
        }
    }
    else {
        printf("Thanks for playing");
    }

    return 0;
}
