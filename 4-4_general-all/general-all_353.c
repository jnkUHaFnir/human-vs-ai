#include <stdio.h>

int main() {
    char answer[10]; // Increase the size based on maximum expected input size
    int guess;
    int diceRoll4 = 0;

    printf("Would you like to guess your next dice? Y/N \n");
    scanf("%9s", answer); // Read a string up to 9 characters, leaving space for null terminator

    if (strcmp(answer, "yes") == 0) {
        printf("What is your guess?\n");
        printf("please key in your number \n");
        scanf("%d", &guess);

        if (guess > diceRoll4) {
            printf("You got it wrong, too high!");
        } else if (guess < diceRoll4) {
            printf("You got it wrong, too low!");
        } else {
            printf("You got it right");
        }
    } else {
        printf("Thanks for playing");
    }

    return 0;
}
