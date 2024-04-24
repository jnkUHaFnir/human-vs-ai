#include <stdio.h>

int main() {
    char answer; // Changed to char since we're reading a single character
    int guess;
    int diceRoll4 = 0; // You might want to generate or calculate a new dice roll here
    
    printf("Would you like to guess your next dice? Y/N \n");
    scanf(" %c", &answer); // Correctly reading a single character into answer

    if (answer == 'Y' || answer == 'y'){ // Checking if answer is 'Y' or 'y'

        printf("What is your guess?\n");
        printf("Please key in your number: \n");
        scanf(" %d", &guess);
        if (guess > diceRoll4 ){
            printf("You got it wrong, too high!\n");
        }
        else if (guess < diceRoll4){
            printf("You got it wrong, too low!\n");
        }
        else {
            printf("You got it right!\n");
        }

    }
    else{ // This 'else' corresponds to not entering 'Y' or 'y'
        printf("Thanks for playing\n");
    }
    return 0;
}
char answer[4]; // Enough space for "yes" + null terminator
scanf("%3s", answer); // Read up to 3 characters as a string
if (strcmp(answer, "yes") == 0) { // You need to #include <string.h> at the top for strcmp
    //...
}
