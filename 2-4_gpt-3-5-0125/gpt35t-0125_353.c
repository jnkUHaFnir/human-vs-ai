char answer[3]; // change int to char and increase the array size to accommodate input
int guess;
int diceRoll4 = 0;

printf("Would you like to guess your next dice? Y/N \n");
scanf(" %s", answer); // change %c to %s to read a string

if (strcmp(answer, "yes") == 0) { // use strcmp to compare strings

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
