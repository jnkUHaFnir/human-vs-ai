char answer[10];
int guess;
int diceRoll4 = 0; // You need to actually generate a random roll here.
printf("Would you like to guess your next dice? Y/N \n");
scanf("%s", answer);

// Now we compare the string answer to "yes" or "Y" if we want to allow single character representation for yes
if (strcmp(answer, "yes") == 0 || strcmp(answer, "Y") == 0){

    printf("What is your guess?\n");
    printf("Please key in your number: \n");
    scanf("%d", &guess);

    // Suppose diceRoll4 should hold the sum of a new dice roll
    // We need to actually generate the random roll before comparing!
    // For example, you could assign a random value like so:
    // diceRoll4 = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);

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
else{
    printf("Thanks for playing\n");
}
