#include <stdio.h>

int main() {
    char answer; // Updated to char type
    int guess;
    int diceRoll4 = 5; // Example value, make sure it is initialized or updated

    printf("Would you like to guess your next dice? Y/N \n");
    scanf(" %c", &answer); // Read a character

    if (answer == 'Y' || answer == 'y') { // Check for 'Y' or 'y' only

        printf("What is your guess?\n");
        printf("Please key in your number: \n");
        scanf(" %d", &guess);
        
        if (guess > diceRoll4) {
            printf("You got it wrong, too high!\n");
        }
        else if (guess < diceRoll4) {
            printf("You got it wrong, too low!\n");
        }
        else {
            printf("You got it right!\n");
        }

    }
    else {
        printf("Thanks for playing\n");
    }

    return 0;
}
