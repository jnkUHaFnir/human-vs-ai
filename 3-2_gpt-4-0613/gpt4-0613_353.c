char answer[10];  //This should be a char array, not int
int guess;
int diceRoll4 = 0;
printf("Would you like to guess your next dice? Y/N \n");
scanf("%s", answer);

if (strcmp(answer, "yes") == 0 ){   //Compare two strings using strcmp()

    printf("What is your guess?\n");
    printf("Please key in your number \n");
    scanf(" %d", &guess);
    if (guess > diceRoll4 ){
        printf(" You got it wrong, too high!");
    }
    else if (guess < diceRoll4){
            printf(" You got it wrong, too low!");
    }
    else {
        printf("You got it right");
    }

}
else{
    printf("Thanks for playing");
}
``` 

In C programming, you can't compare strings using == operator. You should use strcmp() function which is declared in "string.h" header file. If strcmp() returns 0, it means both strings are identical.
