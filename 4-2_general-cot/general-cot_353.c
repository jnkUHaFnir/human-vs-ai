#include <stdio.h>
#include <string.h>

int main() {
    char answer[4]; // Changed to an array of characters to store a string
    int guess;
    int diceRoll4 = 0;
    
    printf("Would you like to guess your next dice? Y/N \n");
    scanf("%3s", answer); // Read a string with a maximum length of 3 characters
    
    if (strcmp(answer, "yes") == 0) { // Compare strings using strcmp function
        printf("What is your guess?\n");
        printf("Please key in your number \n");
        scanf("%d", &guess);
        
        if (guess > diceRoll4) {
            printf("You got it wrong, too high!\n");
        } else if (guess < diceRoll4) {
            printf("You got it wrong, too low!\n");
        } else {
            printf("You got it right\n");
        }
    } else {
        printf("Thanks for playing\n");
    }

    return 0;
}
