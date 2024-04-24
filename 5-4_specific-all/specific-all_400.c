#include <stdio.h>
#include <string.h>

int main() {
    char answer[4]; // Making space for "yes" plus the null terminator
    
    printf("Would you like to guess your next dice? Y/N \n");
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0) {
        int guess;
        int diceRoll4 = 4; // Assume dice rolled 4 for testing purposes

        printf("What is your guess?\n");
        printf("Please key in your number \n");
        scanf(" %d", &guess);

        if (guess > diceRoll4) {
            printf(" You got it wrong, too high!");
        } else if (guess < diceRoll4) {
            printf(" You got it wrong, too low!");
        } else {
            printf("You got it right");
        }
    } else {
        printf("Thanks for playing");
    }

    return 0;
}
