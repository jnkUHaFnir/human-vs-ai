#include<stdio.h>
#include<string.h>  // Include this for strcmp()

int main() {
    char answer[10]; // Adjust array size as needed
    int guess;
    int diceRoll4 = 0; // You'll need to generate a new dice roll here for comparison

    printf("Would you like to guess your next dice? Y/N \n");
    scanf("%s", answer); // Read a string input

    // Compare with "Y" for Yes (assuming you want to use "Y" instead of "yes" based on the prompt)
    if (strcmp(answer, "Y") == 0) {

        printf("What is your guess?\n");
        printf("Please key in your number:\n");
        scanf("%d", &guess);
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
    else{
        printf("Thanks for playing");
    }

    return 0;
}
