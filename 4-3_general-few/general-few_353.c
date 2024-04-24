char answer[10]; // Change to character array to store 'yes' or 'no'
int guess;
int diceRoll4 = 0;
printf("Would you like to guess your next dice? Y/N \n");
scanf(" %s", answer); // Modified to read string input

if (strcmp(answer, "yes") == 0) { // Comparing strings using strcmp function

    printf("What is your guess?\n");
    printf("please key in your number \n");
    scanf(" %d", &guess);
    if (guess > diceRoll4) {
        printf(" You got it wrong, too high!");
    }
    else if (guess < diceRoll4) {
        printf(" You got it wrong, too low!");
    }
    else {
        printf("You got it right");
    }

}
else {
    printf("Thanks for playing");
}
