#include <stdio.h>

int main() {
    char answer; // Changed from int to char
    int guess;
    int diceRoll4 = 0;
    
    printf("Would you like to guess your next dice? Y/N \n");
    scanf(" %c", &answer);

    if (answer == 'y') { // Changed from 'yes' to 'y'
        printf("What is your guess?\n");
        printf("please key in your number \n");
        scanf(" %d", &guess);
        
        if (guess > diceRoll4) {
            printf("You got it wrong, too high!");
        }
        else if (guess < diceRoll4){
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
