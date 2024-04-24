scanf(" %c", &answer);
char answer[4]; // A char array to hold up to 3 characters plus the null terminator.
int guess;
int diceRoll4 = 0;
printf("Would you like to guess your next dice? Y/N \n");
scanf("%3s", answer); // %3s limits the input to 3 characters

if (strcmp(answer, "yes") == 0) { // Use strcmp to compare strings

    printf("What is your guess?\n");
    printf("Please key in your number \n");
    scanf("%d", &guess);
    // Make sure you have the actual dice roll result here instead of a constant 0.
    // The code to generate diceRoll4 would be needed.

    if (guess > diceRoll4){
        printf("You got it wrong, too high!");
    }
    else if (guess < diceRoll4){
        printf("You got it wrong, too low!");
    }
    else {
        printf("You got it right!");
    }

}
else{
    printf("Thanks for playing\n");
}
